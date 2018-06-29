#ifndef BJSIM4_TABLE
#define BJSIM4_TABLE

namespace bjsim4 {

    class TableRuleset {

        public:

        /* Bet */

        unsigned long minBet;
        unsigned long maxBet;
        unsigned long betStep;

        /* Dealer */

        bool hitSoft17;
        bool peekTens;
        bool peekAces;

        /* Insurance */

        bool insurance;
        double insurancePayout;

        /* Play */

        bool restrictedDouble; // only on 10's and 11's
        bool doubleAfterSplit;
        bool splitUnlikeTens;
        bool resplitAces;
        bool acesHalt;
        bool surrender;
        bool earlySurrender;
        unsigned char maxHands;

        /* Cards */

        unsigned int deckCount;
        bool continuousShuffle;
        double maxPenetration;

    };

};

#endif
