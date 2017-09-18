#ifndef BJSIM4_CARDSTACK
#define BJSIM4_CARDSTACK

#include "Card.hpp"
#include "CardStack.hpp"

#include <vector>

namespace bjsim4 {

    class CardStack {

        protected:

        std::vector<Card> cards;

        public:

        CardStack ();
        CardStack ( const CardStack & other );

        bool operator== ( const CardStack & other ) const;
        bool operator!= ( const CardStack & other ) const;

        const std::vector<Card> & getCards () const;
        std::vector<Card> & getCards ();

        CardStack & push ( const Card & card );
        Card pop ();
        CardStack & empty ();

        CardStack & subsume ( CardStack & other );

        bool isEmpty () const;
        unsigned int getSize () const;

    };

};

#endif
