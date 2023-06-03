#include <algorithm>
#include <numeric>
#include <ostream>
#include <vector>

#include "grade.hpp"
#include "student_info.hpp"
#include "median.hpp"

#include "process.hpp"

double median_analysis(const std::vector<Student_info>& students){
    std::vector<double> grades;

    // apply the grade function to each of the student in students and stacks them at the results at the end of grades
    // this doesn't just work because grade is overloaded
    // transform(students.begin(), students.end(),
    //         back_inserter(grades), grade);

    // use an aux. function to handle that
    std::transform(students.begin(), students.end(),
            back_inserter(grades), grade_aux);

    return median(grades);
}

double average(const std::vector<double>& v){
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& v){
    return grade(v.midterm, v.final, average(v.homework));
}

double average_analysis(const std::vector<Student_info>& students){
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
            back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median(const Student_info& s){
    std::vector<double> non_zero;
    std::remove_copy(s.homework.begin(), s.homework.end(),
        back_inserter(non_zero), 0);

    if (non_zero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(non_zero));
}

double optimistic_median_analysis(const std::vector<Student_info>& students){
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
            back_inserter(grades), optimistic_median);
    return median(grades);
}

void write_analysis(std::ostream& out, const std::string& name,
        double analysis(const std::vector<Student_info>&),
        const std::vector<Student_info>& did,
        const std::vector<Student_info>& didnt){
    out << name << ": median(did) = " << analysis(did) <<
                   ", median(didnt) = " << analysis(didnt) << std::endl;
}

void process_records(std::vector<Student_info> did, std::vector<Student_info> didnt){
    // Do stuff

    // write report
    write_analysis(std::cout, "median", median_analysis, did, didnt);
    write_analysis(std::cout, "average", average_analysis, did, didnt);
    write_analysis(std::cout, "median of homeworkd turned in", optimistic_median_analysis, did, didnt);
}
