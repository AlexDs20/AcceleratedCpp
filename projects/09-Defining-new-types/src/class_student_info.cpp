#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include "class_student_info.hpp"

Student_info::Student_info(std::istream& is)
{
    read(is);
}


double grade(double mid, double final, const std::vector<double>& hw)
{
    return 0.4 * mid + 0.4 * final + 0.2 * std::accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);

        in.clear();
    }
    return in;
}

std::istream& Student_info::read(std::istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name() < s2.name();
}
