fa
#ifndef BJSIM4_STRATEGY
#define BJSIM4_STRATEGY

#include "Config.hpp"
#include "Error.hpp"

namespace bjsim4 {

    class Table;

    enum HandDecision {
        STAND,
        HIT,
        DOUBLE,
        SPLIT,
        SURRENDER
    };

    class Option {

        public:

        const Table & getTable () const;

    };

    class HandOption : public Option {

        protected:

        const Table & table;
        const Hand & hand;
        const Amount & bet;

        public:

        HandOption (
            const Hand & hand,
            const Table & table,
            const Amount & bet
        );

        const Hand & getHand () const;

        bool canDouble () const;
        bool canSplit  () const;
        bool canSurrender () const;

    };

    class BetOption {

        protected:

        const Table & table;
        const Hand & hand;
        const Amount & bet;

        public:

        BetOption ();



    };

    class Strategy {

        public:

        Amount decideBet ( const BetOption & option );
        HandDecision decideHand ( const HandOption & option );
        InsuranceDecision decideInsurance ( const InsuranceOption & option );

    };

};
