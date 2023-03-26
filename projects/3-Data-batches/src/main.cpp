#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main()
{
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

    return 0;
}
