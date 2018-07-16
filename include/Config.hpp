#ifndef BJSIM4_CONFIG
#define BJSIM4_CONFIG

namespace bjsim4 {

    class BetConfig {

        public:

        unsigned long minBet;
        unsigned long maxBet;
        unsigned long betStep;

        BetConfig (
            unsigned long minBet,
            unsigned long maxBet,
            unsigned long betStep
        );

    };

    class DealerConfig {

        public:

        bool hitSoft17;
        bool peekTens;
        bool peekAces;

        DealerConfig (
            bool hitSoft17,
            bool peekTens,
            bool peekAces
        );

    };

    enum SurrenderConfig {
        NONE,
        EARLY,
        LATE
    };

    class PlayConfig {

        public:

        bool restrictedDouble;      // may only double on 10 or 11
        bool doubleAfterSplit;
        bool splitUnlikeTens;
        bool resplitAces;
        bool acesHalt;             // cannot play split aces
        bool dealerWinsTies;
        SurrenderConfig surrender;
        unsigned char maxHands;    // # splits allowed + 1
        double blackjackPayout;

        PlayConfig (
            bool restrictedDouble,
            bool doubleAfterSplit,
            bool splitUnlikeTens,
            bool resplitAces,
            bool acesHalt,
            bool dealerWinsTies,
            SurrenderConfig surrender,
            unsigned char maxHands,
            double blackjackPayout
        );

    };

    class CardsConfig {

        public:

        unsigned int deckCount;
        bool continuousShuffle;
        double maxPenetration;

        CardsConfig (
            unsigned int deckCount,
            bool continuousShuffle,
            double maxPenetration
        );

    };

    class InsuranceConfig {

        public:

        double payout;

        InsuranceConfig ( double payout );

    };

    class Config {

        public:

        BetConfig bets;
        DealerConfig dealer;
        PlayConfig play;
        CardsConfig cards;
        InsuranceConfig insurance;

        Config (
            BetConfig bets,
            DealerConfig dealer,
            PlayConfig play,
            CardsConfig cards,
            InsuranceConfig insurance
        );

    };

    class VegasConfig : public Config {};
    class AtlanticCityConfig : public Config {};

};

#endif
