#include "catch.hpp"
#include "RuleSet.hpp"

namespace bjsim4 {

TEST_CASE( "RuleSet access", "[RuleSet]" ) {

    VegasStripRuleSet vegas;
    REQUIRE( vegas.canDoubleAfterSplit() == true );
    REQUIRE( vegas.getBlackjackPayout() - 1.5 < 0.01 );
    REQUIRE( vegas.surrenderIsAllowed() == false );
    REQUIRE( vegas.getDeckCount() == 4 );

    AtlanticCityRuleSet atlantic;
    REQUIRE( atlantic.surrenderIsAllowed() == true );
    REQUIRE( atlantic.getDeckCount() == 8 );

}

};
