#include "Strategy.hpp"
#include "Seat.hpp"
#include "Hand.hpp"

#include <string>

namespace bjsim4 {

double DealerStrategy::decideInsurance (
    const Seat & seat
) {
    return 0.0;
}

double DealerStrategy::decideBet (
    const Seat & seat
) {
    return 0.0;
}

double DealerStrategy::decideSidebet (
    const Seat & seat,
    std::string sidebetName
) {
    return 0.0;
}

HandOption DealerStrategy::decideHand (
    const Seat & seat
) {
    Hand hand = seat.getCurrentHand();
    HandDetail detail = hand.getDetail();

    if ( detail.getBestValue() < 17 )
        return HandOption::HIT;
    if ( detail.getBestValue() > 17 )
        return HandOption::STAND;
    return seat.getRules().dealerStandsOnSoft17()
        ? HandOption::STAND
        : HandOption::HIT;
}

};
