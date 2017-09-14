#include "catch.hpp"
#include "Card.hpp"

#include <string>

namespace bjsim4 {

TEST_CASE( "Card constructors, accessors", "[Card]" ) {

    // Base constructor
    Card sixOfSpades( Suit::SPADES, Rank::SIX );
    REQUIRE( sixOfSpades.getSuit() == Suit::SPADES );
    REQUIRE( sixOfSpades.getRank() == Rank::SIX );

    // Copy constructor
    Card otherSixOfSpades( sixOfSpades );
    REQUIRE( otherSixOfSpades.getSuit() == Suit::SPADES );
    REQUIRE( otherSixOfSpades.getRank() == Rank::SIX );

    Card aceOfHearts( Suit::HEARTS, Rank::ACE );
    Card kingOfDiamonds( Suit::DIAMONDS, Rank::KING );

    REQUIRE( sixOfSpades.isAce() == false );
    REQUIRE( otherSixOfSpades.isAce() == false );
    REQUIRE( aceOfHearts.isAce() == true );
    REQUIRE( kingOfDiamonds.isAce() == false );

    REQUIRE( sixOfSpades.isTenCard() == false );
    REQUIRE( otherSixOfSpades.isTenCard() == false );
    REQUIRE( aceOfHearts.isTenCard() == false );
    REQUIRE( kingOfDiamonds.isTenCard() == true );

    REQUIRE( sixOfSpades.getLowValue() == 6 );
    REQUIRE( otherSixOfSpades.getLowValue() == 6 );
    REQUIRE( aceOfHearts.getLowValue() == 1 );
    REQUIRE( kingOfDiamonds.getLowValue() == 10 );

    REQUIRE( sixOfSpades.getHighValue() == 6 );
    REQUIRE( otherSixOfSpades.getHighValue() == 6 );
    REQUIRE( aceOfHearts.getHighValue() == 11 );
    REQUIRE( kingOfDiamonds.getHighValue() == 10 );

}

TEST_CASE( "Card, comparisons", "[Card]" ) {

    REQUIRE(
        Card( Suit::CLUBS, Rank::TWO ) == Card( Suit::CLUBS, Rank::TWO )
    );

    // Differing rank
    REQUIRE(
        Card( Suit::CLUBS, Rank::TWO ) != Card( Suit::CLUBS, Rank::FOUR )
    );

    // Differing suit
    REQUIRE(
        Card( Suit::CLUBS, Rank::TWO ) != Card( Suit::SPADES, Rank::TWO )
    );

}

TEST_CASE( "Card, toString()", "[Card]" ) {

    REQUIRE(
        Card( Suit::CLUBS, Rank::TWO ).toString() == std::string( "2♣" )
    );

    REQUIRE(
        Card( Suit::DIAMONDS, Rank::TEN ).toString() == std::string( "10♦" )
    );

    REQUIRE(
        Card( Suit::SPADES, Rank::FOUR ).toString() == std::string( "4♠" )
    );

}

};
