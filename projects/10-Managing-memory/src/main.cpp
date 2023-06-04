#include <iostream>

#include "array_and_pointers.hpp"
#include "string_literals.hpp"
#include "arrays_of_pointers.hpp"

int main(int argc, char** argv)
{
    // array_and_pointers();
    // array();
    // pointers();
    // function_pointers();
    // application();
    // pointer_arithmetic();
    // indexing_10_1_5();
    // string_literals();
    // arrays_of_pointers();

    // *argv* is a pointer to the initial element of an array of pointer
    std::cout << argc << std::endl;
    if (argc>1){
        for (int i=0; i<argc; ++i)
            std::cout << *argv[i] << " ";        // argv[i] is a char*
        std::cout << std::endl;
    }
    return 0;
}
