#include "deck.h"
// Trick
Card get_card(Trick trick, uint8_t index) {
    assert(index < 3);
    uint8_t card = trick << (index * 8);
    return {(Suit)(card & 0b11000), (Value)(card & 0b111)};
}

// Deck
bool has_suit(Deck deck, Suit suit) {
    return deck & (0xFF << (suit * 8));
}

