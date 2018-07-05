#ifndef BJSIM4_CONFIG
#define BJSIM4_CONFIG

namespace bjsim4 {

    class BetConfig {

        public:

        unsigned long minBet;
        unsigned long maxBet;
        unsigned long betStep;

        BetConfig ();

    };

    class DealerConfig {

        public:

        bool hitSoft17;
        bool peekTens;
        bool peekAces;

        DealerConfig ();

    };

    class PlayConfig {

        public:

        bool restrictedDouble;
        bool doubleAfterSplit;
        bool splitUnlikeTens;
        bool resplitAces;
        bool acesHalt;
        bool surrender;
        bool earlySurrender;
        unsigned char maxHands;

        PlayConfig ();

    };

    class CardsConfig {

        public:

        unsigned int deckCount;
        bool continuousShuffle;
        double maxPenetration;

        CardsConfig ();

    };

    class Config {

        public:

        BetConfig bets;
        DealerConfig dealer;
        PlayConfig play;
        CardsConfig cards;

        Config ();

    };

    class VegasConfig : public Config {};
    class AtlanticCityConfig : public Config {};

};

#endif
