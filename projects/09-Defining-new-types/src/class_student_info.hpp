#ifndef CLASS_STUDENT_INFO_HPP
#define CLASS_STUDENT_INFO_HPP

#include <iostream>
#include <vector>
#include <string>

// struct does not allow to change the access rights
// i.e. user can still change the grade by accessing the values directly

class Student_info {
    public:
        Student_info(): midterm(0), final(0){};     // default constructor: used to make sure the data members are properly initialized using constructor initializer list
        Student_info(std::istream&);

        double grade() const;
        std::istream& read(std::istream&);
        std::string name() const {return n;};
        bool valid() const {return !homework.empty();};

    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};

bool compare(const Student_info& s1, const Student_info& s2);

#endif
