#include "card.h"
#include "random.h"

#include <algorithm>

void shuffle_deck(Card deck[32]) {
    std::shuffle(deck, deck + 32, Random::gen);
}

bool operator<(const Card& lhs, const Card& rhs) {
    if (lhs.suit != rhs.suit) {
        return lhs.suit < rhs.suit;
    }
    return lhs.value < rhs.value;
}

// TODO(Sigull): Don't know if it should be in place.
void sort_cards_suit(Card hand[], uint32_t n) {
    std::sort(hand, hand + n);
}
