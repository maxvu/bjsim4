#include "Hand.hpp"

namespace bjsim4 {

HandDetail::HandDetail ( const Hand & hand ) {
    bool hasAce = false;
    const auto cards = hand.getCards();
    uint8_t handLo = 0;
    uint8_t handHi = 0;
    for ( uint8_t i = 0; i < cards.size(); i++ ) {
        const Card & card = cards[ i ];
        uint8_t cardLo = card.getLowValue();
        uint8_t cardHi = card.getHighValue();
        if ( card.getRank() == Rank::ACE ) {
            handLo += cardLo;
            handHi += hasAce ? cardLo : cardHi;
            hasAce = true;
        } else {
            handLo += cardLo;
            handHi += cardLo;
        }
    }
    this->value = handLo;
    this->flags = 0;
    if ( handHi != handLo && handHi <= 21 )
        this->flags |= SOFT;
    if ( cards.size() == 2 ) {
        if ( handHi == 21 || handLo == 21 )
            this->flags |= HandDetail::Flags::BLACKJACK;
        if ( cards[ 0 ].getRank() == cards[ 1 ].getRank() )
            this->flags |= HandDetail::Flags::PAIR;
    }
}

uint8_t HandDetail::getLowValue () const {
    return this->value;
}

uint8_t HandDetail::getHighValue () const {
    if ( this->isSoft() )
        return this->value + 10;
    return this->value;
}

uint8_t HandDetail::getBestValue () const {
    uint8_t hiValue = this->getHighValue();
    if ( hiValue > 21 ) {
        return this->getLowValue();
    } else {
        return hiValue;
    }

}

bool HandDetail::isPair () const {
    return this->flags & HandDetail::Flags::PAIR;
}

bool HandDetail::isSoft () const {
    return this->flags & HandDetail::Flags::SOFT;
}

bool HandDetail::isHard () const {
    return !this->isSoft();
}

bool HandDetail::isBust () const {
    return this->getBestValue() > 21;
}

bool HandDetail::isBlackjack () const {
    return this->flags & HandDetail::Flags::BLACKJACK;
}

bool HandDetail::is21 () const {
    return (
        this->value == 21 ||
        ( this->value == 11 && this->flags & HandDetail::Flags::SOFT )
    );
}

Hand::Hand () {

}

Hand::Hand ( const Hand & other ) : stack( other.stack ) {

}

Hand::Hand ( const Card & first, const Card & second ) {
    this->stack.push( first ).push( second );
}

const std::vector<Card> & Hand::getCards () const {
    return this->stack.getCards();
}

Hand & Hand::deal ( const Card & card ) {
    this->stack.getCards().push_back( card );
    return *this;
}

std::vector<Hand> Hand::split () const {
    if ( this->stack.getSize() != 2 ) {
        // TODO: probably should except here.
        return std::vector<Hand>();
    }
    return std::vector<Hand>({
        Hand().deal( this->stack.getCards()[ 0 ] ),
        Hand().deal( this->stack.getCards()[ 1 ] )
    });
}

HandDetail Hand::getDetail () const {
    return HandDetail( *this );
}

Hand & Hand::addBet ( unsigned int bet ) {
    this->bets.push_back( bet );
    return *this;
}

const std::vector<unsigned int> & Hand::getBets () const {
    return this->bets;
}

uint8_t Hand::getBetCount () const {
    return this->bets.size();
}

};
