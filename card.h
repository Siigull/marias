#ifndef CARD_H
#define CARD_H

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
    SEVEN = 7,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
} Special_Value;

typedef struct Card {
    Suit suit;
    Value value;
    Special_Value special_value;
} Card;


// 32 cards, 7 - ACE (8 cards) in each suit (4)
const Card deck[] = {
    (Card){suit: HEARTS, value: Value::SEVEN, Special_Value::SEVEN}, (Card){suit: HEARTS, value: Value::EIGHT, Special_Value::EIGHT},
    (Card){suit: HEARTS, value: Value::NINE,  Special_Value::NINE},  (Card){suit: HEARTS, value: Value::TEN,   Special_Value::TEN},
    (Card){suit: HEARTS, value: Value::JACK,  Special_Value::JACK},  (Card){suit: HEARTS, value: Value::QUEEN, Special_Value::QUEEN},
    (Card){suit: HEARTS, value: Value::KING,  Special_Value::KING},  (Card){suit: HEARTS, value: Value::ACE,   Special_Value::ACE},
    (Card){suit: DIAMONDS, value: Value::SEVEN, Special_Value::SEVEN}, (Card){suit: DIAMONDS, value: Value::EIGHT, Special_Value::EIGHT},
    (Card){suit: DIAMONDS, value: Value::NINE,  Special_Value::NINE},  (Card){suit: DIAMONDS, value: Value::TEN,   Special_Value::TEN},
    (Card){suit: DIAMONDS, value: Value::JACK,  Special_Value::JACK},  (Card){suit: DIAMONDS, value: Value::QUEEN, Special_Value::QUEEN},
    (Card){suit: DIAMONDS, value: Value::KING,  Special_Value::KING},  (Card){suit: DIAMONDS, value: Value::ACE,   Special_Value::ACE},
    (Card){suit: CLUBS, value: Value::SEVEN, Special_Value::SEVEN}, (Card){suit: CLUBS, value: Value::EIGHT, Special_Value::EIGHT},
    (Card){suit: CLUBS, value: Value::NINE,  Special_Value::NINE},  (Card){suit: CLUBS, value: Value::TEN,   Special_Value::TEN},
    (Card){suit: CLUBS, value: Value::JACK,  Special_Value::JACK},  (Card){suit: CLUBS, value: Value::QUEEN, Special_Value::QUEEN},
    (Card){suit: CLUBS, value: Value::KING,  Special_Value::KING},  (Card){suit: CLUBS, value: Value::ACE,   Special_Value::ACE},
    (Card){suit: SPADES, value: Value::SEVEN, Special_Value::SEVEN}, (Card){suit: SPADES, value: Value::EIGHT, Special_Value::EIGHT},
    (Card){suit: SPADES, value: Value::NINE,  Special_Value::NINE},  (Card){suit: SPADES, value: Value::TEN,   Special_Value::TEN},
    (Card){suit: SPADES, value: Value::JACK,  Special_Value::JACK},  (Card){suit: SPADES, value: Value::QUEEN, Special_Value::QUEEN},
    (Card){suit: SPADES, value: Value::KING,  Special_Value::KING},  (Card){suit: SPADES, value: Value::ACE,   Special_Value::ACE},
};

// Shuffles array in place
void shuffle_deck(Card deck[32]);

void sort_cards_suit();

#endif
