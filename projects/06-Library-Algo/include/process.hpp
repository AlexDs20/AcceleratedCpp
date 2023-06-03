#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <vector>
#include <ostream>
#include "student_info.hpp"

double median_analysis(const std::vector<Student_info>& students);
void process_records(std::vector<Student_info> did, std::vector<Student_info> didnt);
void write_analysis(std::ostream& out, const std::string& name,
        double analysis(const std::vector<Student_info>&),
        const std::vector<Student_info>& did,
        const std::vector<Student_info>& didnt);

#endif
