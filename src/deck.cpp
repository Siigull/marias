#include "deck.h"

#include <string>

// Trick
Card get_card(Trick trick, uint8_t index) {
    assert(index < 3);
    uint8_t card = trick << (index * 8);
    return {(Suit)((card & 0b11000) >> 3), (Value)(card & 0b111)};
}

Card string_to_card(std::string str) {
    Card card;

    if (str.size() != 2) {
        card.err = 101;
        return card;
    }

    switch(str[0]) {
        case 'H': card.suit = 0; break;
        case 'D': card.suit = 1; break;
        case 'C': card.suit = 2; break;
        case 'S': card.suit = 3; break;
        default: card.err = 0b101;
    }

    switch(str[1]) {
        case '7': card.value = 0; break;
        case '8': card.value = 1; break;
        case '9': card.value = 2; break;
        case 'T': card.value = 3; break;
        case 'J': card.value = 4; break;
        case 'Q': card.value = 5; break;
        case 'K': card.value = 6; break;
        case 'A': card.value = 7; break;
    }
}

std::string card_to_string(Card card) {
    std::string ret = "";

    switch(card.suit) {
        case Suit::HEARTS:   ret+='H'; break;
        case Suit::DIAMONDS: ret+='D'; break;
        case Suit::CLUBS:    ret+='C'; break;
        case Suit::SPADES:   ret+='S'; break;
        default: return "";
    }

    switch(card.value) {
        case Value::SEVEN: ret+='7'; break;
        case Value::EIGHT: ret+='8'; break;
        case Value::NINE:  ret+='9'; break;
        case Value::TEN:   ret+='T'; break;
        case Value::JACK:  ret+='J'; break;
        case Value::QUEEN: ret+='Q'; break;
        case Value::KING:  ret+='K'; break;
        case Value::ACE:   ret+='A'; break;
        default: return "";
    }

    return ret;
}

// Deck
bool has_suit(Deck deck, Suit suit) {
    return deck & (0xFF << (suit * 8));
}
