#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include <list>
#include "student_info.hpp"

// inline: -> copy the body of the function where the function is called
// => avoid having to call the function
inline double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& homework);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::vector<Student_info> slow_extract_failed(std::vector<Student_info>&);
std::vector<Student_info> iter_extract_failed(std::vector<Student_info>&);
std::list<Student_info> list_extract_failed(std::list<Student_info>&);

#endif
