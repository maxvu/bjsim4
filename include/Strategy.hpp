#ifndef BJSIM4_STRATEGY
#define BJSIM4_STRATEGY

#include "HandOption.hpp"
#include "Seat.hpp"

#include <string>

namespace bjsim4 {

    class Strategy {

        public:

        virtual double decideInsurance (
            const Seat & seat
        ) =0;

        virtual double decideBet (
            const Seat & seat
        ) =0;

        virtual double decideSidebet (
            const Seat & seat,
            std::string sidebetName
        ) =0;

        virtual HandOption decideHand (
            const Seat & seat
        ) =0;

    };

    class DealerStrategy : public Strategy {

        double decideInsurance (
            const Seat & seat
        );

        double decideBet (
            const Seat & seat
        );

        double decideSidebet (
            const Seat & seat,
            std::string sidebetName
        );

        HandOption decideHand (
            const Seat & seat
        );

    };

};

#endif
