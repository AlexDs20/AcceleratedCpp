#include <iostream>
#include "array_and_pointers.hpp"

void array_and_pointers() {
    int a = 5;
    int *b = nullptr;
    std::cout << b << " " << &b << " " << *(&b) << std::endl;
    std::cout << (b==0) << " " << (b==nullptr) << std::endl;
    b = &a;

    std::cout << "a: " << a << std::endl;
    std::cout << "&a: " << &a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "*b: " << *b << std::endl;
    std::cout << "&b: " << &b << std::endl;
    *b = 4;
    std::cout << "*b=4 -> a =  " << a << std::endl;
    std::cout << "&b: " << &b << std::endl;
    std::cout << "*(&b): " << *(&b) << std::endl;
    std::cout << "&b+1: " << &b+1 << std::endl;
    std::cout << "*(&b+1): " << *(&b+1) << std::endl;
    std::cout << "*(&b-1): " << *(&b-1) << std::endl;
}
