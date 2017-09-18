#include "RuleSet.hpp"

namespace bjsim4 {

RuleSet::RuleSet (
    uint8_t deckCount,
    float blackjackPayout,
    bool insurance,
    bool soft17Stand,
    bool peekTen,
    bool peekAce,
    bool loseTies,
    bool surrender,
    bool splitUnlikeTens,
    bool acesHalt,
    bool doubleAfterSplit,
    uint8_t maxBets,
    uint8_t maxSplits
) :
    deckCount( deckCount ),
    blackjackPayout( blackjackPayout ),
    insurance( insurance ),
    soft17Stand( soft17Stand ),
    peekTen( peekTen ),
    peekAce( peekAce ),
    loseTies( loseTies ),
    surrender( surrender ),
    splitUnlikeTens( splitUnlikeTens ),
    haltOnSplitAces( acesHalt ),
    doubleAfterSplit( doubleAfterSplit ),
    maxBets( maxBets ),
    maxSplits( maxSplits )
{

}

uint8_t RuleSet::getDeckCount () const {
    return this->deckCount;
}

float RuleSet::getBlackjackPayout () const {
    return this->blackjackPayout;
}

bool RuleSet::insuranceIsProvided () const {
    return this->insurance;
}

bool RuleSet::dealerStandsOnSoft17 () const {
    return this->soft17Stand;
}

bool RuleSet::dealerPeeksTen () const {
    return this->peekTen;
}

bool RuleSet::dealerPeeksAce () const {
    return this->peekAce;
}

bool RuleSet::dealerWinsTies () const {
    return this->loseTies;
}

bool RuleSet::surrenderIsAllowed () const {
    return this->surrender;
}

bool RuleSet::canSplitUnlikeTens () const {
    return this->splitUnlikeTens;
}

bool RuleSet::acesHalt () const {
    return this->haltOnSplitAces;
}

bool RuleSet::canDoubleAfterSplit () const {
    return this->doubleAfterSplit;
}

uint8_t RuleSet::getMaxBets () const {
    return this->maxBets;
}

uint8_t RuleSet::getMaxSplits () const {
    return this->maxSplits;
}

VegasStripRuleSet::VegasStripRuleSet (

) : RuleSet (
    4,      // deckCount
    1.5,    // blackjackPayout
    true,   // insurance
    true,   // soft17Stand
    true,   // peekTen
    true,   // peekAce
    false,  // loseTies
    false,  // surrender
    true,   // splitUnlikeTens
    false,  // haltOnSplitAces
    true,   // doubleAfterSplit
    4,      // maxBets
    4       // maxSplits
) {

}

AtlanticCityRuleSet::AtlanticCityRuleSet (

) : RuleSet (
    8,      // deckCount
    1.5,    // blackjackPayout
    true,   // insurance
    true,   // soft17Stand
    true,   // peekTen
    true,   // peekAce
    false,  // loseTies
    true,   // surrender
    true,   // splitUnlikeTens
    false,  // haltOnSplitAces
    true,   // doubleAfterSplit
    4,      // maxBets
    4       // maxSplits
) {

}

};
