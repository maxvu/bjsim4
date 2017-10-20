#ifndef BJSIM4_PLAYER
#define BJSIM4_PLAYER

#include <string>

namespace bjsim4 {

    class Player {

        protected:

        std::string name;
        double bankroll;

        public:

        Player ( const std::string & name, double bankrollInit );

        const std::string & getName () const;
        double getBankroll () const;

        Player & award ( double amount );
        Player & deduct ( double amount );

    };

};

#endif
