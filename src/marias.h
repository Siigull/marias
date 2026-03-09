#ifndef MARIAS_H
#define MARIAS_H

#include "deck.h"


/**
 * TODO(Sigull): Need an interface between player and game.
 * In game it will be just cards (note: Queen being for hlaska is a little weird)
 *  Probably just number 0-31
 * In chossing, will it be just one big enum of options?
 *  Or split it into more enums based on substate (first choosing, fleking...).
 * 
 */

enum class CHOOSE_MOVE : uint8_t {
    PASS, // Good/dobry
    
    GAME,
    SEVEN,
    HUNDRED,

    FLEK_GAME,
    FLEK_SEVEN,
    FLEK_HUNDRED,

    BETL, 
    DURCH,

    SENTINEL // Not actual. Keep this last or code will break
};
// bitfield of CHOOSE_MOVE
#define Choose_Moves uint16_t

enum class GAME_PHASE {
    CHOOSING,
    GAME,
};

enum class GAME_TYPE {
    GAME,
    SEVEN,
    HUNDRED,
    HUNDRED_SEVEN,

    BETL,
    DURCH,
};

// TODO(Sigull): Think about if a player should be outside of Game struct
//               Maybe just move stuff like balance elsewhere
typedef struct {
    CHOOSE_MOVE (*play_choose);
    Card (*play_card);
    int balance;
    Deck hand;
    Deck won;
} Player;

uint8_t iter_player(uint8_t prev);

typedef struct {
    GAME_PHASE phase;
    GAME_TYPE type;

    Player players[3];
    uint8_t starting_player_index; // Don't like this name
    uint8_t attacking_player_index;
    uint8_t current_player_index;

    Trick talon;
} Game;

Game game_init();

#endif
