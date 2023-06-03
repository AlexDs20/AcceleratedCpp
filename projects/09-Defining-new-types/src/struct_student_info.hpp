#ifndef STUDENT_INFO_HPP
#define STUDENT_INFO_HPP

#include <iostream>
#include <vector>
#include <string>

#if 0

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream& read(std::istream&);
    double grade() const;       // the const here says that we will not change any of the data member
                                // compared to previous double grade(const Student_info& s);
                                // serves the same purpose as const Student_info&
                                // *const member function*
                                // cannot call nonconst member on a const object
};
#endif

#endif
