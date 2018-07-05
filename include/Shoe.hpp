#ifndef BJSIM4_SHOE
#define BJSIM4_SHOE

#include "Card.hpp"
#include "Config.hpp"
#include "Error.hpp"

namespace bjsim4 {

    class ShoeCount {

        protected:

        unsigned int values[ 13 ];

        public:

        ShoeCount ( unsigned int deckCount );

        ShoeCount & remove ( Card card );
        double getProbability ( Rank rank ) const;
        double getProbabilityTenCard () const;

    };

    class Shoe {

        protected:

        unsigned int deckCount;
        std::list<Card> cards;
        ShoeCount count;

        public:

        Shoe ( unsigned int deckCount );
        Shoe ( const Shoe & other );

        Card draw ();
        Shoe & reset ();

        double getPenetration () const;
        const ShoeCount & getCount () const;

    };

};
