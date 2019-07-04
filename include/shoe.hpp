#ifndef BJSIM4_SHOE
#define BJSIM4_SHOE

namespace bjsim4 {

    class shoe {

        protected:
        std::vector<card> _undrawn;
        std::vector<card> _drawn;

        public:
        shoe ();

        shoe & add_cards ( const std::vector<card> & cards );

        shoe & reshuffle ();
        card draw ();

    };

}

#endif
