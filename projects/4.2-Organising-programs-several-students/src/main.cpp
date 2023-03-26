#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

#include "median.hpp"
#include "utils.hpp"


int main()
{
    std::vector<Student_info> students;
    Student_info record;
    std::string::size_type maxlen = 0;

    while(read(std::cin, record)){
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
    }

    // order the students by name
    sort(students.begin(), students.end(), compare);

    //
    for (std::vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {

        // Write the name and pad with spaces
        std::cout << students[i].name
            << std::string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
                << std::setprecision(prec);
        } catch (std::domain_error e){
            std::cout << e.what();
        }
        std::cout << std::endl;
    }

    return 0;
}
