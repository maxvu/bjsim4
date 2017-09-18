#include "catch.hpp"
#include "Card.hpp"
#include "Hand.hpp"

#include <vector>

namespace bjsim4 {

TEST_CASE( "Hand constructors, manipulation, HandDetail", "[Hand]" ) {

    // Constructors, deal()
    Hand pairOfFours(
        Card( Suit::CLUBS, Rank::FOUR ),
        Card( Suit::DIAMONDS, Rank::FOUR )
    );
    Hand anotherPairOfFours( pairOfFours );
    Hand hardFifteen;
    hardFifteen.deal( Card( Suit::SPADES, Rank::FIVE ) );
    hardFifteen.deal( Card( Suit::HEARTS, Rank::JACK ) );

    // Composition w/ getCards()
    REQUIRE( pairOfFours.getCards().size() == 2 );
    REQUIRE( anotherPairOfFours.getCards().size() == 2 );
    REQUIRE( hardFifteen.getCards().size() == 2 );

    // getBetCount(), addBet()
    REQUIRE( pairOfFours.getBets().size() == 0 );
    REQUIRE( anotherPairOfFours.getBets().size() == 0 );
    REQUIRE( hardFifteen.getBets().size() == 0 );
    REQUIRE( pairOfFours.getBetCount() == 0 );
    REQUIRE( anotherPairOfFours.getBetCount() == 0 );
    REQUIRE( hardFifteen.getBetCount() == 0 );

    anotherPairOfFours.addBet( 20 );
    REQUIRE( anotherPairOfFours.getBets().size() == 1 );
    REQUIRE( anotherPairOfFours.getBetCount() == 1 );

    // hard total, soft total, blackjack, 21-not-BJ, bust
    // HandDetail, hard total
    {
        HandDetail detail = Hand(
            Card( Suit::SPADES, Rank::SEVEN ),
            Card( Suit::SPADES, Rank::FIVE )
        ).getDetail();
        REQUIRE( detail.getLowValue() == 12 );
        REQUIRE( detail.getHighValue() == 12 );
        REQUIRE( detail.getBestValue() == 12 );
        REQUIRE( detail.isPair() == false );
        REQUIRE( detail.isSoft() == false );
        REQUIRE( detail.isHard() == true );
        REQUIRE( detail.isBust() == false );
        REQUIRE( detail.isBlackjack() == false );
        REQUIRE( detail.is21() == false );
    }

    // HandDetail, soft total
    {
        HandDetail detail = Hand(
            Card( Suit::SPADES, Rank::ACE ),
            Card( Suit::SPADES, Rank::TWO )
        ).getDetail();
        REQUIRE( detail.getLowValue() == 3 );
        REQUIRE( detail.getHighValue() == 13 );
        REQUIRE( detail.getBestValue() == 13 );
        REQUIRE( detail.isPair() == false );
        REQUIRE( detail.isSoft() == true );
        REQUIRE( detail.isHard() == false );
        REQUIRE( detail.isBust() == false );
        REQUIRE( detail.isBlackjack() == false );
        REQUIRE( detail.is21() == false );
    }

    // HandDetail, bust
    {
        HandDetail detail = Hand(
            Card( Suit::SPADES, Rank::TEN ),
            Card( Suit::SPADES, Rank::KING )
        ).deal(
            Card( Suit::SPADES, Rank::FOUR )
        ).getDetail();
        REQUIRE( detail.getLowValue() == 24 );
        REQUIRE( detail.getHighValue() == 24 );
        REQUIRE( detail.getBestValue() == 24 );
        REQUIRE( detail.isPair() == false );
        REQUIRE( detail.isSoft() == false );
        REQUIRE( detail.isHard() == true );
        REQUIRE( detail.isBust() == true );
        REQUIRE( detail.isBlackjack() == false );
        REQUIRE( detail.is21() == false );
    }

    // HandDetail, blackjack
    {
        HandDetail detail = Hand(
            Card( Suit::SPADES, Rank::TEN ),
            Card( Suit::SPADES, Rank::ACE )
        ).getDetail();
        REQUIRE( detail.getLowValue() == 11 );
        REQUIRE( detail.getHighValue() == 21 );
        REQUIRE( detail.getBestValue() == 21 );
        REQUIRE( detail.isPair() == false );
        REQUIRE( detail.isSoft() == true );
        REQUIRE( detail.isHard() == false );
        REQUIRE( detail.isBust() == false );
        REQUIRE( detail.isBlackjack() == true );
        REQUIRE( detail.is21() == true );
    }

    // HandDetail, 21 (not blackjack)
    {
        HandDetail detail = Hand(
            Card( Suit::SPADES, Rank::EIGHT ),
            Card( Suit::SPADES, Rank::FOUR )
        ).deal(
            Card( Suit::SPADES, Rank::NINE )
        ).getDetail();
        REQUIRE( detail.getLowValue() == 21 );
        REQUIRE( detail.getHighValue() == 21 );
        REQUIRE( detail.getBestValue() == 21 );
        REQUIRE( detail.isPair() == false );
        REQUIRE( detail.isSoft() == false );
        REQUIRE( detail.isHard() == true );
        REQUIRE( detail.isBust() == false );
        REQUIRE( detail.isBlackjack() == false );
        REQUIRE( detail.is21() == true );
    }


}

TEST_CASE( "Hand split", "[Hand]" ) {

    {
        Hand pairOfAces(
            Card( Suit::CLUBS, Rank::ACE ),
            Card( Suit::DIAMONDS, Rank::ACE )
        );

        std::vector<Hand> splitHands = pairOfAces.split();

        REQUIRE( splitHands.size() == 2 );
        splitHands[ 0 ].deal( Card( Suit::DIAMONDS, Rank::FOUR ) );
        splitHands[ 1 ].deal( Card( Suit::DIAMONDS, Rank::KING ) );

        {
            HandDetail detail = splitHands[ 0 ].getDetail();
            REQUIRE( detail.getBestValue() == 15 );
            REQUIRE( detail.isSoft() == true );
            REQUIRE( detail.isBlackjack() == false );
            REQUIRE( detail.is21() == false );
        }

        {
            HandDetail detail = splitHands[ 1 ].getDetail();
            REQUIRE( detail.getBestValue() == 21 );
            REQUIRE( detail.isSoft() == true );
            REQUIRE( detail.isBlackjack() == true );
            REQUIRE( detail.is21() == true );
        }

    }

    {
        Hand pairOfTwos(
            Card( Suit::CLUBS, Rank::TWO ),
            Card( Suit::DIAMONDS, Rank::TWO )
        );

        std::vector<Hand> splitHands = pairOfTwos.split();

        REQUIRE( splitHands.size() == 2 );
        splitHands[ 0 ].deal( Card( Suit::DIAMONDS, Rank::NINE ) );
        splitHands[ 1 ].deal( Card( Suit::DIAMONDS, Rank::KING ) );

        {
            HandDetail detail = splitHands[ 0 ].getDetail();
            REQUIRE( detail.getBestValue() == 11 );
            REQUIRE( detail.isSoft() == false );
            REQUIRE( detail.isBlackjack() == false );
            REQUIRE( detail.is21() == false );
        }

        {
            HandDetail detail = splitHands[ 1 ].getDetail();
            REQUIRE( detail.getBestValue() == 12 );
            REQUIRE( detail.isSoft() == false );
            REQUIRE( detail.isBlackjack() == false );
            REQUIRE( detail.is21() == false );
        }

    }

}

};
