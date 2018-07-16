#ifndef BJSIM4_SHOE
#define BJSIM4_SHOE

#include "Card.hpp"
#include "Config.hpp"
#include "Error.hpp"

namespace bjsim4 {


    class ShoeCount;

    class Shoe {

        protected:

        std::list<Card> toDraw;
        std::list<Card> discarded;
        unsigned long values[ 13 ]; // A -> K

        Shoe & shuffle ();

        public:

        Shoe ( unsigned int deckCount );
        Shoe ( const Shoe & other );

        Card draw ();
        Shoe & reshuffle ();
        double getRankIncidence ( Rank rank );
        double getValueIncidence ( unsigned char Value );

    };

};

#endif
