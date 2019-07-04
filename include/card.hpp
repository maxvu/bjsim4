#ifndef BJSIM4_CARD
#define BJSIM4_CARD

#include "Rank.hpp"
#include "Suit.hpp"

namespace bjsim4 {

    class Card {

        protected:
        Rank _rank;
        Suit _suit;

        Card ( Rank rank, Suit suit );

        Rank rank () const;
        Suit suit () const;

    };

}

#endif
