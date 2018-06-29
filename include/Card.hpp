#ifndef BJSIM4_CARD
#define BJSIM4_CARD

#include <string>

namespace bjsim4 {

    enum Suit {
        CLUBS = 1,
        DIAMONDS = 2,
        HEARTS = 3,
        SPADES = 4
    };

    enum Rank {
        ACE = 1,
        TWO = 2,
        THREE = 3,
        FOUR = 4,
        FIVE = 5,
        SIX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10,
        JACK = 11,
        QUEEN = 12,
        KING = 13
    };

    class Card {

        protected:

        Suit suit;
        Rank rank;

        public:

        Card ( Suit suit, Rank rank );
        Card ( const Card & other );

        Suit getSuit () const;
        Rank getRank () const;

        bool isAce () const;
        bool isTenCard () const;

        std::string toString () const;

    };

};

#endif
