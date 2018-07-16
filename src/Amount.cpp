#include "Amount.hpp"

namespace bjsim4 {

Amount::Amount () : amount( 0 ) {

}

Amount::Amount ( const Amount & other ) : amount( other.amount ) {

}

Amount::operator unsigned long () {
    return this->amount;
}

Amount & Amount::operator+= ( unsigned long u ) {
    this->amount += u;
    return *this;
}

Amount & Amount::operator-= ( unsigned long u ) {
    this->amount -= u;
    return *this;
}

Amount & Amount::operator= ( unsigned long u ) {
    this->amount = u;
    return *this;
}

};
