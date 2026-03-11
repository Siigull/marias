#include "player.h"

#include <string>

namespace PTerminal {

Choose_Moves play_choose(Player* p_this, Choose_Moves moves) {
    uint8_t end = static_cast<uint8_t>(CHOOSE_MOVE::SENTINEL);
    for (uint8_t i=0; i < end; i++) {
        
    }
}

// Maybe some template kind of shit here, just to be fancy
Card choose_any(Deck hand) {
    printf("Choose from:\n  ");
    for(int i=0; i<32; i++) {
        if (hand & (1 << i)) {
            Card card;
            card.raw = i;
            printf("%s, ", card_to_string(card));
        }
    }

    Card card;
    char suit, value;
    while (true) {
        printf("\nPick a card ([H|D|C|S][7|8|9|T|J|Q|K|A]):");
        scanf("%s", &suit, &value);

        card = string_to_card(std::string(suit, value));

        if (card.err == 0b101) {
            printf("\nInvalid suit or value. Try again.\n");
        }
    }

    return card;
}

Card play_card(Player* p_this, CARD_MOVE move, Deck hand) {
    switch(move) {
        case CARD_MOVE::CHOOSE_TRUMP:

    }
}

Deck play_cards(Player* p_this, CARDS_MOVE move, Deck hand) {
    switch(move) {
        case CARDS_MOVE::THROW_TWO:

    }
}

}
