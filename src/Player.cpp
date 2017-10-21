#include "Player.hpp"
#include "Strategy.hpp"

#include <string>
#include <stdexcept>

namespace bjsim4 {

Player::Player (
    const std::string & name,
    double bankrollInit,
    Strategy & strategy
) :
    name( name ),
    bankroll( bankrollInit ),
    strategy( strategy )
{

}

const Strategy & Player::getStrategy () const {
    return this->strategy;
}

const std::string & Player::getName () const {
    return this->name;
}

double Player::getBankroll () const {
    return this->bankroll;
}

Player & Player::award ( double amount ) {
    this->bankroll += amount;
    return *this;
}

Player & Player::deduct ( double amount ) {
    if ( amount >= this->bankroll )
        throw std::runtime_error( "Insufficient Player bankroll." );
    this->bankroll -= amount;
    return *this;
}

};
