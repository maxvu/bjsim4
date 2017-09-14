#ifndef BJSIM4_SHOE
#define BJSIM4_SHOE

#include "CardStack.hpp"
#include "Card.hpp"

#include <vector>

namespace bjsim4 {

    class Shoe {

        private:

        CardStack undrawn;
        CardStack discard;

        public:

        Shoe ( uint8_t deckCount );

        Card draw ();
        Shoe & reshuffle ();

        double getPenetration () const;
        bool isExhausted () const;

    };

};

#endif
