#ifndef BJSIM4_HAND
#define BJSIM4_HAND

#include "card.hpp"

namespace bjsim4 {

    class hand {

        protected:
        std::vector<card> _cards;

        hand ();

        hand & add_card ( card card );

        bool is_soft () const;
        bool is_pair () const;
        bool is_blackjack () const;
        unsigned char score () const;

    };

}

#endif
