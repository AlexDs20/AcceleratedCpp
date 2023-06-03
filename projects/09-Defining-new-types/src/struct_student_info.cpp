#include "struct_student_info.hpp"

#include <iostream>
#include <vector>
#include <numeric>

#if 0

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

std::istream& Student_info::read(std::istream& in)
{
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double grade(double mid, double final, const std::vector<double>& hw)
{
    return 0.4 * mid + 0.4 * final + 0.2 * std::accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
}

double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
    // using ::grade -> means that we use a version of *grade* that is not a member of anything
    // without it, the compiler would try to call Student_info::grade
}

#endif
