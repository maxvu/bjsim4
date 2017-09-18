#ifndef BJSIM4_HAND
#define BJSIM4_HAND

#include "CardStack.hpp"

#include <vector>

namespace bjsim4 {

    /*
        ...
    */

    class Hand;

    class HandDetail {

        private:

        enum Flags {
            SOFT = 1,
            PAIR = 2,
            BLACKJACK = 4
        };

        uint8_t value;
        uint8_t flags;

        public:

        HandDetail ( const Hand & hand );

        uint8_t getLowValue () const;
        uint8_t getHighValue () const;
        uint8_t getBestValue () const;

        bool isPair () const;
        bool isSoft () const;
        bool isHard () const;
        bool isBust () const;
        bool isBlackjack () const;
        bool is21 () const;

    };

    class Hand {

        protected:

        CardStack stack;
        std::vector<unsigned int> bets;

        public:

        Hand ();
        Hand ( const Hand & other );
        Hand ( const Card & first, const Card & second );

        const std::vector<Card> & getCards () const;

        Hand & deal ( const Card & card );
        std::vector<Hand> split () const;

        HandDetail getDetail () const;

        Hand & addBet ( unsigned int bet );
        const std::vector<unsigned int> & getBets () const;
        uint8_t getBetCount () const;

    };

};

#endif
