#ifndef BJSIM4_HAND
#define BJSIM4_HAND

#include <string>
#include <list>
#include <pair>

#include "Amount.hpp"
#include "Card.hpp"

namespace bjsim4 {

    class Hand {

        protected:

        std::list<Card> cards;

        public:

        Hand ();
        Hand ( const Hand & other );

        Hand & deal ( Card card );

        bool operator<  ( const Hand & other ) const;
        bool operator>  ( const Hand & other ) const;
        bool operator== ( const Hand & other ) const;
        bool operator!= ( const Hand & other ) const;
        bool operator<= ( const Hand & other ) const;
        bool operator>= ( const Hand & other ) const;

        bool isHard () const;
        bool isSoft () const;
        bool isPair () const;
        bool isBust () const;
        bool isBlackjack () const;

        unsigned char getValue () const;
        const std::list<Card> & getCards () const;

        std::string toString () const;

    };

};

#endif
