#include "Str.h"
#include <cctype>

Str operator+(const Str& lhs, const Str& rhs) {
    Str ret(lhs);
    ret += rhs;
    return ret;
}

std::ostream& operator<<(std::ostream& os, const Str& s){
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
};

std::istream& operator>>(std::istream& is, Str& s){
    s.data.clear();

    char c;
    while (is.get(c) && std::isspace(c))
        ;

    if (is) {
        do  s.data.push_back(c);
        while ( is.get(c) && !std::isspace(c) ) ;

        if (is)
            is.unget();
    }

    return is;
};
