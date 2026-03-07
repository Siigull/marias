#ifndef CARD_H
#define CARD_H

#include "common.h"

#include <algorithm>

typedef enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
} Suit;

// For regular games
// Ten is before ace
typedef enum Value {
    SEVEN = 7,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Value;

// Value for betl and durch
// 'Normal' card values
typedef enum Special_Value {
    SPEC_SEVEN = 7,
    SPEC_EIGHT,
    SPEC_NINE,
    SPEC_TEN,
    SPEC_JACK,
    SPEC_QUEEN,
    SPEC_KING,
    SPEC_ACE,
} Special_Value;

typedef struct Card {
    Suit suit;
    Value value;
    Special_Value special_value;
} Card;


// 32 cards, 7 - ACE (8 cards) in each suit (4)
const Card const_deck[] = {
    {HEARTS, SEVEN, SPEC_SEVEN},  {HEARTS, EIGHT, SPEC_EIGHT},
    {HEARTS, NINE,  SPEC_NINE},   {HEARTS, TEN,   SPEC_TEN},
    {HEARTS, JACK,  SPEC_JACK},   {HEARTS, QUEEN, SPEC_QUEEN},
    {HEARTS, KING,  SPEC_KING},   {HEARTS, ACE,   SPEC_ACE},
    {DIAMONDS, SEVEN, SPEC_SEVEN},{DIAMONDS, EIGHT, SPEC_EIGHT},
    {DIAMONDS, NINE,  SPEC_NINE}, {DIAMONDS, TEN,   SPEC_TEN},
    {DIAMONDS, JACK,  SPEC_JACK}, {DIAMONDS, QUEEN, SPEC_QUEEN},
    {DIAMONDS, KING,  SPEC_KING}, {DIAMONDS, ACE,   SPEC_ACE},
    {CLUBS, SEVEN, SPEC_SEVEN},   {CLUBS, EIGHT, SPEC_EIGHT},
    {CLUBS, NINE,  SPEC_NINE},    {CLUBS, TEN,   SPEC_TEN},
    {CLUBS, JACK,  SPEC_JACK},    {CLUBS, QUEEN, SPEC_QUEEN},
    {CLUBS, KING,  SPEC_KING},    {CLUBS, ACE,   SPEC_ACE},
    {SPADES, SEVEN, SPEC_SEVEN},  {SPADES, EIGHT, SPEC_EIGHT},
    {SPADES, NINE,  SPEC_NINE},   {SPADES, TEN,   SPEC_TEN},
    {SPADES, JACK,  SPEC_JACK},   {SPADES, QUEEN, SPEC_QUEEN},
    {SPADES, KING,  SPEC_KING},   {SPADES, ACE,   SPEC_ACE},
};

// Shuffles array in place
void shuffle_deck(Card deck[32]);

void sort_cards_suit(Card hand[], uint32_t n);

#endif
