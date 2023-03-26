#include <iostream>
#include <stdexcept>
#include <vector>

#include "median.hpp"
#include "utils.hpp"

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// vector<double>& -> creates a reference i.e. direct access to the argument without copy
// const vector<double>& -> assures that the content will not change -> constant
double grade(double midterm, double final, const std::vector<double>& hw)
{
    if (hw.size() == 0)
        throw std::domain_error("Student has done no homework!");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
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
// to be able to sort our struct, we need a function to compare 2 objects
bool compare(const Student_info& x, const Student_info& y){
    return x.name < y.name;
}
