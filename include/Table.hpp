#ifndef BJSIM4_TABLE
#define BJSIM4_TABLE

#include "Config.hpp"
#include "Error.hpp"

namespace bjsim4 {

    class Seat {

        protected:

        std::string name;
        Amount bankroll;
        Strategy & strategy;

        public:

        Seat (
            const std::string & name,
            const Amount & amount,
            const Strategy & strategy
        );l

        const std::string & getName ();
        Amount & getBankroll ();
        Strategy & getStrategy();
        Hand & getCurrentHand ();

        const Amount & getBankroll () const;
        const Hand & getCurrentHand () const;

    };

    class Table {

        protected:

        Config config;
        std::vector<Seat> seats;
        Shoe shoe;

        public:

        Table ( const Config & config );

        Table & addPlayer (
            std::string name,
            const Strategy & strategy
        );

        const Config & getConfig () const;
        const std::vector<Seat> & getSeats () const;
        const Shoe & getShoe () const;

    };

};

#endif
