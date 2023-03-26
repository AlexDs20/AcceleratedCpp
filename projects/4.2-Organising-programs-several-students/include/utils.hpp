#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <iostream>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};
bool compare(const Student_info& x, const Student_info& y);

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& homework);
double grade(const Student_info& s);

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& is, Student_info& s);
#endif
