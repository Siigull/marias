#include "marias.h"
#include "random.h"
#include "player.h"

#include <string>
#include <cstring>

uint8_t iter_player(uint8_t prev) {
    return ++prev % 3;
}

std::string choose_move_to_string(CHOOSE_MOVE move) {
    switch (move) {
        case CHOOSE_MOVE::PASS:         return "PASS";
        case CHOOSE_MOVE::GAME:         return "GAME";
        case CHOOSE_MOVE::SEVEN:        return "SEVEN";
        case CHOOSE_MOVE::HUNDRED:      return "HUNDRED";
        case CHOOSE_MOVE::FLEK_GAME:    return "FLEK_GAME";
        case CHOOSE_MOVE::FLEK_SEVEN:   return "FLEK_SEVEN";
        case CHOOSE_MOVE::FLEK_HUNDRED: return "FLEK_HUNDRED";
        case CHOOSE_MOVE::BETL:         return "BETL"; 
        case CHOOSE_MOVE::DURCH:        return "DURCH";
        case CHOOSE_MOVE::SENTINEL:     return "SENTINEL";
    }

    return "UNIMPLEMENTED " + std::to_string(static_cast<int>(move));
}

Game game_init() {
    Game game{};
    
    game.phase = GAME_PHASE::CHOOSING;
    game.type = GAME_TYPE::GAME;
    game.starting_player_index = 2;
    
    for (int i = 0; i < 3; i++) {
        game.players[i].balance     = 0;
        game.players[i].play_choose = nullptr;
        game.players[i].play_cards   = nullptr;
    }
        
    return game;
}

void deal_cards(Game* game) {
    // Check it can be set with a single memset, that there is no padding in between.
    assert(game->players_hand + sizeof(game->players_hand) == &game->attackers_5);
    assert((&game->attackers_5) + sizeof(game->attackers_5) == game->players_won_cards);
    memset(
        game->players_hand,
        0,
        sizeof(game->players_hand) +
          sizeof(game->attackers_5) +
          sizeof(game->players_won_cards)
    );

    uint8_t ass[32] = {
        0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,
        3,3,3,3,3
    };
    
    for (int i=31; i>0; i--) {
        int j = Random::get_random(0, i);
        uint8_t tmp = ass[i];
        ass[i] = ass[j];
        ass[j] = tmp;
    }
    
    for (int i=0; i<32; i++) {
        game->players_hand[ass[i]] |= (1u << i);
    }
}

void attacker_choose_trump(Game* game) {
    Player* attacker = &game->players[game->attacking_player_index];
    Deck* att_hand = &(game->players_hand[game->attacking_player_index]);

    Card card = attacker->play_card(attacker, CARD_MOVE::CHOOSE_TRUMP, *att_hand);

    game->trump = card;

    (*att_hand) |= game->attackers_5;
    game->attackers_5 = 0;
}

// TODO(Sigull): For non ai implementation he should be able to take
//               cards back. Maybe have one call for choosing game and throw away
void attacker_throw_two(Game* game) {
    Player* attacker = &game->players[game->attacking_player_index];
    Deck* att_hand = &(game->players_hand[game->attacking_player_index]);

    Deck cards = attacker->play_cards(attacker, CARDS_MOVE::THROW_TWO, *att_hand);

    assert(__builtin_popcount(cards) == 2);

    game->throw_away |= ~cards;
}

bool attacker_choose_game(Game* game) {
    Player* attacker = &game->players[game->attacking_player_index];

    Choose_Moves moves = static_cast<Choose_Moves>(CHOOSE_MOVE::GAME) |
                         static_cast<Choose_Moves>(CHOOSE_MOVE::HUNDRED) |
                         static_cast<Choose_Moves>(CHOOSE_MOVE::BETL) |
                         static_cast<Choose_Moves>(CHOOSE_MOVE::DURCH);

    if (game->players_hand[game->attacking_player_index] & 
        0x01 << (game->trump.suit * 8)) {
        moves |= static_cast<Choose_Moves>(CHOOSE_MOVE::SEVEN);
    }

    attacker->play_choose(attacker, moves);
}

void game_start(Game* game) {
    game->starting_player_index = iter_player(game->starting_player_index);
    game->attacking_player_index = game->starting_player_index;

    while (game->phase == GAME_PHASE::CHOOSING) {
        deal_cards(game);

        attacker_choose_trump(game);

        attacker_throw_two(game);

        attacker_choose_game(game);
    }
}
