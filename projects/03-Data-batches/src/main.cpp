#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>


void using_mean();
int using_median();


int main()
{
    // using_mean();
    int v;
    v = using_median();
    return v;
}

void using_mean(){
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    // Get midterm and final grades
    std::cout << "Enter midterm and final exam grades: ";
    double midterm, final;
    std::cin >> midterm >> final;
    std::cout << midterm << final;

    // homework grades
    std::cout << "Enter homework grades, follow with CTRL+d: ";

    int count = 0;
    double sum = 0.0;

    double x;

    while (std::cin >> x){
        ++count;
        sum += x;
    }

    // write result
    std::streamsize prec = std::cout.precision();

    std::cout << "Final grade is " << std::setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
        << std::setprecision(prec) << std::endl;

    // alternative way to set the precision
    std::cout.precision(prec);
}

int using_median(){
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    std::vector<double> homework;

    double value;
    while (std::cin >> value){
        homework.push_back(value);
    }

    // define a new name for the type of std::vector<double>::size_type
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0){
        std::cout << std::endl << "You must enter your grades. "
                                  "Please try again" << std::endl;
        return 1;
    }

    std::sort(homework.begin(), homework.end());

    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
                           : homework[mid];

    std::cout << median << std::endl;

    return 0;
}
