#ifndef BJSIM4_CARD
#define BJSIM4_CARD

#include <string>

namespace bjsim4 {

    enum Suit {
        CLUBS    = 1,
        DIAMONDS = 2,
        HEARTS   = 3,
        SPADES   = 4
    };

    enum Rank {
        ACE   = 1,
        TWO   = 2,
        THREE = 3,
        FOUR  = 4,
        FIVE  = 5,
        SIX   = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE  = 9,
        TEN   = 10,
        JACK  = 11,
        QUEEN = 12,
        KING  = 13
    };

    const Suit allSuits[] = {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };

    const Rank allRanks[] = {
        ACE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    class Card {

        private:

        Suit suit;
        Rank rank;

        public:

        Card ( Suit suit, Rank rank );
        Card ( const Card & other );

        bool operator== ( const Card & other ) const;
        bool operator!= ( const Card & other ) const;
        bool operator< ( const Card & other ) const;

        Suit getSuit () const;
        Rank getRank () const;

        bool isAce () const;
        bool isTenCard () const;

        uint8_t getLowValue () const;
        uint8_t getHighValue () const;

        std::string toString () const;

    };

};

#endif
