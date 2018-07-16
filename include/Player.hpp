#ifndef BJSIM4_PLAYER
#define BJSIM4_PLAYER

#include <string>

#include "Amount.hpp"

namespace bjsim4 {

    class Player {

        protected:

        std::string name;
        Amount bankroll;
        Strategy & strategy;

        public:

        Player (
            std::string name,
            Amount bankrollInit,
            Strategy & strategy
        );

        const std::string & getName () const;
        const Amount & getAmount () const;
        const Strategy & getStrategy () const;

        Amount & getAmount ();
        Strategy & getStrategy ();

    };

};

#endif
