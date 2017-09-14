#include "Shoe.hpp"

#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>

namespace bjsim4 {

Shoe::Shoe ( uint8_t deckCount ) {
    if ( !deckCount )
        throw std::invalid_argument( "Can't have an empty shoe." );
    for ( uint8_t i = 0; i < deckCount; i++ ) {
        for ( uint8_t j = 0; j < 4; j++ ) {
            for ( uint8_t k = 0; k < 13; k++ ) {
                this->discard.push( Card( allSuits[ j ], allRanks[ k ] ) );
            }
        }
    }
    this->reshuffle();
}

Card Shoe::draw () {
    Card drawn( this->undrawn.pop() );
    this->discard.push( drawn );
    return drawn;
}

Shoe & Shoe::reshuffle () {
    this->undrawn.subsume( this->discard );
    std::shuffle(
        this->undrawn.getCards().begin(),
        this->undrawn.getCards().end(),
        std::default_random_engine(
            std::chrono::system_clock::now().time_since_epoch().count()
        )
    );
    return *this;
}

double Shoe::getPenetration () const {
    return (
        this->discard.getSize() / (
            this->undrawn.getSize() + this->discard.getSize()
        )
    );
}

bool Shoe::isExhausted () const {
    return this->undrawn.isEmpty();
}

};
