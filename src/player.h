#ifndef PLAYER_H
#define PLAYER_H

#include "marias.h"

namespace PTerminal {

Choose_Moves play_choose(Player* p_this, Choose_Moves moves);

Card play_card(Player* p_this, CARD_MOVE move, Deck hand);

Deck play_cards(Player* p_this, CARDS_MOVE move, Deck hand);

}

#endif
