#include <iostream>
#include <cstring>      // strlen
#include <string>

#include "string_literals.hpp"


std::size_t string_length(const char *p){
    // size not including '\0'
    std::size_t size = 0;
    while (*p++ != '\0')
        ++size;
    return size;
};


void string_literals(){
    const char sl[] = {
        'H', 'e', 'l', 'l', 'o', '\0'
    };

    std::cout << "Size of \"Hello\"" << std::endl;
    std::cout << sizeof("Hello") << std::endl;

    std::cout << "Size of string literal: 'H', 'e', 'l', 'l', 'o', '\\0'" << std::endl;
    std::cout << sizeof(sl) << std::endl;

    for (int i=0; i<sizeof(sl); ++i)
        std::cout << sl[i] << ", ";
    std::cout << std::endl;

    const char *p = "abcde,\0";
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << p[0] << std::endl;
    int i = 0;
    while (p[i] != '\0') {
        std::cout << p[i] << std::endl;
        ++i;
    }

    std::cout << string_length(sl) << std::endl;
    std::cout << string_length(p) << std::endl;
    std::cout << strlen(p) << std::endl;

    std::string s(sl);
    std::string s2("Hello");
    for (std::string::const_iterator it=s.begin(); it!=s.end(); ++it)
        std::cout << *it;
    std::cout << std::endl;
    std::cout << *(s.end()-1) << std::endl;     // giving o, not '\0'
};
