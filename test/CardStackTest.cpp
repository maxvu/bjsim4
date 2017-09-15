#include "catch.hpp"
#include "Card.hpp"
#include "CardStack.hpp"

#include <vector>

namespace bjsim4 {

TEST_CASE( "CardStack constructors, accessors", "[CardStack]" ) {

    CardStack a;
    a.push( Card( Suit::DIAMONDS, Rank::TWO ) );
    a.push( Card( Suit::DIAMONDS, Rank::FOUR ) );
    a.push( Card( Suit::DIAMONDS, Rank::SIX ) );

    CardStack b = a;
    b.push( Card( Suit::SPADES, Rank::EIGHT ) );

    REQUIRE( a.getSize() == 3 );
    REQUIRE( b.getSize() == 4 );

    REQUIRE( a.getCards().front() == b.getCards().front() );
    REQUIRE( a.getCards().back() != b.getCards().back() );

    REQUIRE( !a.isEmpty() );
    REQUIRE( !b.isEmpty() );

    Card popped = a.pop();
    REQUIRE( popped == Card( Suit::DIAMONDS, Rank::SIX ) );
    REQUIRE( a.getSize() == 2 );

    a.subsume( b );
    REQUIRE( a.getSize() == 6 );
    REQUIRE( a.getCards().back() == Card( Suit::SPADES, Rank::EIGHT ) );

    a.empty();
    REQUIRE( a.getSize() == 0 );
    REQUIRE( a.isEmpty() );

}

};
