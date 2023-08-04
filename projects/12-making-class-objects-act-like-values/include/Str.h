#pragma once
#include <iostream>
#include <cstring>
#include <iterator>
#include <vector>

class Str {
    // friend allow the function though not a member function, to access the private members
    friend std::istream& operator>>(std::istream&, Str&);
    public:
        typedef std::vector<char>::size_type size_type;

        Str(){};
        Str(size_type n, char c): data(n, c) {}

        Str(const char* cp){
            std::copy(cp, cp+std::strlen(cp), std::back_inserter(data));
        }
        template <class In>
        Str(In b, In e) {
            std::copy(b, e, std::back_inserter(data));
        }

        Str& operator+=(const Str& rhs) { std::copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data)); return *this;};
        char& operator[](size_type i) {return data[i];}
        const char& operator[](size_type i) const {return data[i];}
        size_type size() const {return data.size();}

    private:
        std::vector<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
