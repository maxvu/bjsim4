#ifndef BJSIM4_RULESET
#define BJSIM4_RULESET

#include <cstdint>

namespace bjsim4 {

    class RuleSet {

        public:

        protected:

        // Game
        uint8_t deckCount;
        float blackjackPayout;
        bool insurance;

        // Dealer
        bool soft17Stand;
        bool peekTen;
        bool peekAce;
        bool loseTies;

        // Hand
        bool surrender;
        bool splitUnlikeTens;
        bool haltOnSplitAces;
        bool doubleAfterSplit;
        uint8_t maxBets;
        uint8_t maxSplits;

        public:

        RuleSet (
            uint8_t deckCount,
            float blackjackPayout,
            bool insurance,
            bool soft17Stand,
            bool peekTen,
            bool peekAce,
            bool loseTies,
            bool surrender,
            bool splitUnlikeTens,
            bool haltOnSplitAces,
            bool doubleAfterSplit,
            uint8_t maxBets,
            uint8_t maxSplits
        );

        uint8_t getDeckCount () const;
        float getBlackjackPayout () const;
        bool insuranceIsProvided () const;

        bool dealerStandsOnSoft17 () const;
        bool dealerPeeksTen () const;
        bool dealerPeeksAce () const;
        bool dealerWinsTies () const;

        bool surrenderIsAllowed () const;
        bool canSplitUnlikeTens () const;
        bool acesHalt () const;
        bool canDoubleAfterSplit () const;
        uint8_t getMaxBets () const;
        uint8_t getMaxSplits () const;

    };

    class VegasStripRuleSet : public RuleSet {

        public:

        VegasStripRuleSet ();

    };

    class AtlanticCityRuleSet : public RuleSet {

        public:

        AtlanticCityRuleSet ();

    };

};

#endif
