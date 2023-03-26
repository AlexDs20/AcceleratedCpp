#include <vector>
#include <stdexcept>

#include "grade.hpp"
#include "median.hpp"
#include "student_info.hpp"

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
