#ifndef BJSIM4_ERROR
#define BJSIM4_ERROR

namespace bjsim4 {

    class Error {

        public:

        const char * getMessage ();

    };

    class InvalidConfigError : public Error {

        public:

        InvalidConfigError(
            const char * optionName,
            const char * givenValue,
            const char * reason
        );

        const char * getMessage ();

    };

};

#endif
