#ifndef MARIAS_H
#define MARIAS_H

#include "deck.h"

enum class GAME_PHASE{
    CHOOSING,
    GAME,
};

// TODO(Sigull): Think about if a player should be outside of Game struct
//               Maybe just move stuff like balance elsewhere
typedef struct {
    void* play_move;
    int balance;
    Deck hand;
    Deck won;
} Player;

typedef struct {
    GAME_PHASE phase;
    Player players[3];

    Trick talon;

    
} Game;

#endif
