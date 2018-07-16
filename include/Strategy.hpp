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

    class Strategy {

        public:

        Amount decideBet ( const BetOption & option );
        Amount decideInsurance ( const InsuranceOption & option );
        HandDecision decideHand ( const HandOption & option );

    };

};

#endif
