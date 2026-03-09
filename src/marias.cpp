#include "marias.h"

#include <string>

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
    game.attacking_player_index = 0;
    game.current_player_index = 0;
    
    for (int i = 0; i < 3; i++) {
        game.players[i].balance     = 0;
        game.players[i].hand        = 0;
        game.players[i].won         = 0;
        game.players[i].play_choose = nullptr;
        game.players[i].play_card   = nullptr;
    }
    
    game.talon = 0;
    
    return game;
}

void deal_cards(Game* game) {
    uint8_t counts[4] = {12,10,,}; // Need to care about index
    for (int i=0; i < 32; i++) {
        game.players[i];
    }
}

void game_start(Game* game) {
    game->starting_player_index = iter_player(game->starting_player_index);
    game->attacking_player_index = game->starting_player_index;

    while (game->phase == GAME_PHASE::CHOOSING) {
        deal_cards(game);
    }
}
