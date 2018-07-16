#ifndef BJSIM4_OPTION
#define BJSIM4_OPTION

#include "Card.hpp"

namespace bjsim4 {

    class Table;
    class Seat;

    class Option {

        public:

        Option (
            const Table & table,
            const Seat & seat
        );

        const Table & getTable () const;
        const Seat & getSeat () const;

    };

    class BetOption : public Option {

        public:

        BetOption (
            const Table & table,
            const Seat & seat
        );

    };

    class PostDealOption : public Option {

        public:

        PostDealOption ( Card upCard );

        Card getUpCard () const;
        bool hasPeeked () const;

    };

    class InsuranceOption : public PostDealOption {

        public:

        InsuranceOption (
            const Table & table,
            const Seat & seat,
            Card upCard,
            bool hasPeeked
        );

        double getPayout () const;

    };

    class HandOption : public PostDealOption {

        public:

        HandOption (
            const Table & table,
            const Seat & seat,
            const Hand & hand,
            Card upCard,
            bool hasPeeked
        );

        const Hand & getHand () const;

        bool canDouble () const;
        bool canSplit  () const;
        bool canSurrender () const;

    };

};

#endif
