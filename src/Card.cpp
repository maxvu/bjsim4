#include "Card.hpp"

#include <string>

namespace bjsim4 {

Card::Card ( Suit suit, Rank rank ) : suit( suit ), rank( rank ) {

}

Card::Card ( const Card & other ) : suit( other.suit ), rank( other.rank ) {

}

bool Card::operator== ( const Card & other ) const {
    return this->rank == other.rank && this->suit == other.suit;
}

bool Card::operator!= ( const Card & other ) const {
    return !( *this == other );
}

bool Card::operator< ( const Card & other ) const {
    if ( this->rank == other.rank ) {
        return this->suit < other.suit;
    }
    if ( this->rank < other.rank ) return true;
    return false;
}

Suit Card::getSuit () const {
    return this->suit;
}

Rank Card::getRank () const {
    return this->rank;
}

bool Card::isAce () const {
    return this->rank == Rank::ACE;
}

bool Card::isTenCard () const {
    return this->rank >= Rank::TEN;
}

uint8_t Card::getLowValue () const {
    if ( this->isTenCard() )
        return 10;
    else if ( this->isAce() )
        return 1;
    else
        return this->rank;
}

uint8_t Card::getHighValue () const {
    if ( this->isAce() )
        return 11;
    else
        return this->getLowValue();
}

std::string Card::toString () const {
    std::string card;
    switch ( this->rank ) {
        case ACE:   card += "A"; break;
        case TWO:   card += "2"; break;
        case THREE: card += "3"; break;
        case FOUR:  card += "4"; break;
        case FIVE:  card += "5"; break;
        case SIX:   card += "6"; break;
        case SEVEN: card += "7"; break;
        case EIGHT: card += "8"; break;
        case NINE:  card += "9"; break;
        case TEN:   card += "10"; break;
        case JACK:  card += "J"; break;
        case QUEEN: card += "Q"; break;
        case KING:  card += "K"; break;
    }
    switch ( this->suit ) {
        case CLUBS:    card += "♣"; break;
        case DIAMONDS: card += "♦"; break;
        case HEARTS:   card += "♥"; break;
        case SPADES:   card += "♠"; break;
    }
    return card;
}

};
