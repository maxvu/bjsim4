#ifndef BJSIM4_TABLE
#define BJSIM4_TABLE

#include <vector>

#include "Config.hpp"
#include "Error.hpp"
#include "Player.hpp"

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
        );

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

        Table (
            const Config & config,
            std::list<Player> players
        );

        const Config & getConfig () const;
        const std::vector<Seat> & getSeats () const;
        const Shoe & getShoe () const;

    };

};

#endif
