#include <iostream>
#include "Str.h"

int main()
{
    const char* char_ptr = "This is a Str";
    Str my_string(char_ptr);
    Str new_string;
    new_string = "This is a string automatically converted from const char*";
    std::cout << my_string << std::endl;
    std::cout << new_string << std::endl;

    Str input;
    std::cout << "Enter String" << std::endl;
    std::cin >> input;
    std::cout << input << std::endl;

    Str another("Concatenation First");
    another += " Second";
    std::cout << another << std::endl;

    Str another_one = my_string + input;
    Str one_more = my_string + " a const char*";
    std::cout << another_one << std::endl;
    std::cout << one_more << std::endl;
}
