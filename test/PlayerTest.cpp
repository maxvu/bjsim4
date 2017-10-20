#include "catch.hpp"
#include "Player.hpp"

namespace bjsim4 {

TEST_CASE( "Player constructor, manipulation", "[Player]" ) {

    double tenThousand = 10000.00;

    Player somePlayer( "somePlayer", tenThousand );
    REQUIRE( somePlayer.getName() == "somePlayer" );
    REQUIRE( somePlayer.getBankroll() == tenThousand );

    REQUIRE( somePlayer.deduct( 5000.00 ).getBankroll() - 5000.00 < 0.1 );

    // Deducting more than bankroll throws.
    try {
        somePlayer.deduct( 99999 );
        REQUIRE( false );
    } catch ( std::exception & ex ) {

    }

};

};
