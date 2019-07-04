#ifndef BJSIM4_COUNT
#define BJSIM4_COUNT

namespace bjsim4 {

    class count {

        protected:
        std::unordered_map<rank,unsigned int> _frequencies;
        std::unordered_map<rank,unsigned int> _base;

        public:
        count ();

        double probability_of ( Rank rank ) const;

        count & reset ();

    };

}

#endif
