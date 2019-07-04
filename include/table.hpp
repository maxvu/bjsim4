#ifndef BJSIM4_TABLE
#define BJSIM4_TABLE

namespace bjsim4 {

    class table {

        protected:
        shoe              _shoe;
        std::vector<hand> _active_hands;
        std::vector<hand> _played_hands;
        hand              _dealer_hand;

        public:
        table ();

        const card & up_card () const;

        bool playing () const;
        const hand & hand () const;
        table & hit ();
        table & stand ();
        bool can_split () const;
        table & split ();
        bool can_double () const;
        table & double ();

        const std::vector<hand> & played_hands () const;

        table & reset ();

    };

}

#endif
