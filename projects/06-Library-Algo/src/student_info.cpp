#include <iostream>
#include <stdexcept>
#include <vector>

#include "student_info.hpp"

//
// to be able to sort our struct, we need a function to compare 2 objects
bool compare(const Student_info& x, const Student_info& y){
    return x.name < y.name;
}

// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
    if (in) {
        // start by clearing anything that may already be in hw
        hw.clear();

        double x;
        while(in >> x)
            hw.push_back(x);

        // When we stop being able to read -> set the state as failure, thus reading will fail the next time we try.
        // Reset so that next time we do std::cin, it works
        in.clear();
    }

    return in;
}

std::istream& read(std::istream& is, Student_info& s){
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}
