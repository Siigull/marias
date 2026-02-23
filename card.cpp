#include "card.h"
#include "random.h"

void shuffle_deck(Card deck[32]) {
    std::shuffle(deck, deck + 32, Random::gen);
}

void sort_cards_suit(Card deck[]) {
    
}
