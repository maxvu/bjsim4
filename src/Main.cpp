#include <iostream>

#include "Shoe.hpp"

int main ( int argc, char ** argv ) {

    bjsim4::Shoe shoe( 1 );

    while ( !shoe.isExhausted() ) {
        std::cout << shoe.draw().toString() << " ";
    }

    std::cout << std::endl;

    std::cout << "main: ok" << std::endl;
    return 0;
}
