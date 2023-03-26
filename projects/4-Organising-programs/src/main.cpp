#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>


// When creating a function like this, we copy the content into vec
double median(std::vector<double> vec);

double grade(double midterm, double final, double homework);

// vector<double>& -> creates a reference i.e. direct access to the argument without copy
// const vector<double>& -> assures that the content will not change -> constant
double grade(double midterm, double final, const std::vector<double>& hw);

// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

int main()
{
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    std::cout << "Enter midterm and final: ";
    double midterm, final;
    std::cin >> midterm >> final;

    std::vector<double> homework;
    read_hw(std::cin, homework);

    try {
        double final_grade = grade(midterm, final, homework);
        std::streamsize prec = std::cout.precision();
        std::cout << "Your final grade is " << std::setprecision(5)
                  << final_grade << std::setprecision(prec) << std::endl;
    } catch (std::domain_error) {
        std::cout << std::endl << "You must enter your grades.  "
            "Please try again." << std::endl;
        return 1;
    }

    return 0;
}
