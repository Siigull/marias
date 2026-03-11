#ifndef DECK_H
#define DECK_H

#include "common.h"

#include <optional>
#include <algorithm>

typedef enum Suit : uint8_t {
    HEARTS = 0,
    DIAMONDS = 1,
    CLUBS = 2,
    SPADES = 3,
} Suit;

// Dont know how to handle ordering and different types of games.
// Leave it open for now.

// For regular games
// Ten is before ace
typedef enum Value : uint8_t {
    SEVEN = 0,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Value;


// TODO(Sigull): When in single 5 bit value, it is basically 
// index to the deck bitmap. Dont know If I want to use this.
typedef union {
    struct {
        uint8_t value : 3;
        uint8_t suit  : 2;
        uint8_t err   : 3;
    };

    uint8_t raw;
} Card;

Card string_to_card(std::string str);
std::string card_to_string(Card card);

// Packed as 5 bits per card, padded to 8 bits
// 000ssvvv
// #define Trick uint32_t

typedef union {
    struct {
        uint8_t first : 8;
        uint8_t second : 8;
        uint8_t third : 8;
    };

    uint32_t raw;
} Trick;

Card get_card(Trick trick, uint8_t index);

// Bit field
#define Deck uint32_t

bool has_suit(Deck deck, Suit suit);

#endif
