#ifndef BJSIM4_AMOUNT
#define BJSIM4_AMOUNT

namespace bjsim4 {

    class Amount {

        protected:

        unsigned long amount;

        public:

        Amount ();
        Amount ( const Amount & other );

        operator unsigned long ();
        Amount & operator+= ( unsigned long u );
        Amount & operator-= ( unsigned long u );
        Amount & operator= ( unsigned long u );

    };

};

#endif
