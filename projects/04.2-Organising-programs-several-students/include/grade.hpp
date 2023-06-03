#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "student_info.hpp"

// inline: -> copy the body of the function where the function is called
// => avoid having to call the function
inline double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& homework);
double grade(const Student_info&);

#endif
