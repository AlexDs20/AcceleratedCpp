#include <iostream>
#include <string>
#include <vector>

#include "struct_student_info.hpp"      // removed by preprocessor to avoid linking error with the class case
#include "class_student_info.hpp"

template<class T>
void print(const T& t){
    typename T::const_iterator it = t.begin();
    std::cout << *it++;

    while (it != t.end())
        std::cout << ", " << *it++;
    std::cout << std::endl;
}


int main()
{
    std::vector<int> v({0,1,2,3,4,2,3,1,2});
    print(v);
    std::string v2("HELLO");
    print(v2);

    // empty constructor
    Student_info student;
    student.read(std::cin);
    std::cout << student.name() << "\t" << student.grade() << std::endl;

    std::cout << "HERE" << std::endl;

    // initialize by reading from cin
    Student_info s2(std::cin);
    std::cout << s2.name() << "\t" << s2.grade() << std::endl;

    return 0;
}
