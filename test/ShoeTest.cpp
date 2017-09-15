#include "catch.hpp"
#include "Card.hpp"
#include "CardStack.hpp"
#include "Shoe.hpp"

#include <vector>
#include <set>

namespace bjsim4 {

TEST_CASE( "Shoe constructors, manipulation", "[Shoe]" ) {

    Shoe a( 1 ), b( 2 ), c( 4 );

    REQUIRE( a.getPenetration() < 0.01 );
    REQUIRE( b.getPenetration() < 0.01 );
    REQUIRE( c.getPenetration() < 0.01 );

    REQUIRE( !a.isExhausted() );
    REQUIRE( !b.isExhausted() );
    REQUIRE( !c.isExhausted() );

    // Only see each card once.
    std::set<Card> cardsSeen;
    while ( !c.isExhausted() ) {
        REQUIRE( cardsSeen.count( c.draw() ) == 0 );
    }
    REQUIRE( c.isExhausted() );
    REQUIRE( c.getPenetration() - 100.0 < 0.01 );

    c.reshuffle();
    REQUIRE( !c.isExhausted() );
    REQUIRE( c.getPenetration() < 0.01 );

}

};
