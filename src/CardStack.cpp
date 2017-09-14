#include "Card.hpp"
#include "CardStack.hpp"

#include <list>

namespace bjsim4 {

CardStack::CardStack () {

}

CardStack::CardStack ( const CardStack & other ) : cards( other.cards ) {

}

const std::vector<Card> & CardStack::getCards () const {
    return this->cards;
}

std::vector<Card> & CardStack::getCards () {
    return this->cards;
}

CardStack & CardStack::push ( const Card & card ) {
    this->cards.push_back( card );
    return *this;
}

Card CardStack::pop () {
    Card popped( this->cards.back() );
    this->cards.pop_back();
    return popped;
}

CardStack & CardStack::empty () {
    this->cards.clear();
    return *this;
}

CardStack & CardStack::subsume ( CardStack & other ) {
    this->cards.insert(
        this->cards.end(),
        other.cards.begin(),
        other.cards.end()
    );
    other.empty();
    return *this;
}

bool CardStack::isEmpty () const {
    return this->cards.size() == 0;
}

unsigned int CardStack::getSize () const {
    return this->cards.size();
}

};
