#include "Card.hpp"

namespace bjsim4 {

Card::Card ( Suit suit, Rank rank ) : suit( suit ), rank( rank ) {

}

Card::Card ( const Card & other ) : suit( other.suit ), rank( other.rank ) {

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
    switch ( this->rank ) {
        case TEN:
        case JACK:
        case QUEEN:
        case KING: return true; break;
        default: return false;
    }
}

std::string Card::toString () const {
    std::string asStr;

    switch ( this->rank ) {
        case ACE:   asStr += "A"; break;
        case TWO:   asStr += "2"; break;
        case THREE: asStr += "3"; break;
        case FOUR:  asStr += "4"; break;
        case FIVE:  asStr += "5"; break;
        case SIX:   asStr += "6"; break;
        case SEVEN: asStr += "7"; break;
        case EIGHT: asStr += "8"; break;
        case NINE:  asStr += "9"; break;
        case TEN:   asStr += "10"; break;
        case JACK:  asStr += "J"; break;
        case QUEEN: asStr += "Q"; break;
        case KING:  asStr += "K"; break;
    }

    switch ( this->suit ) {
        case CLUBS: asStr += "♣"; break;
        case DIAMONDS: asStr += "♦"; break;
        case HEARTS: asStr += "♥"; break;
        case SPADES: asStr += "♠"; break;
    }

    return asStr;
}

};
