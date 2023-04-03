#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <cctype>   // contains isspace

#include "grade.hpp"
#include "student_info.hpp"


std::vector<std::string> split_string_by_spaces(const std::string&);


int main()
{
    std::vector<Student_info> students;
    Student_info record;
    std::string::size_type maxlen = 0;

    std::string text = "This is a test.";
    std::vector<std::string> words = split_string_by_spaces(text);
    for (std::vector<std::string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
        std::cout << *iter << std::endl;

    if (false) {
        while(read(std::cin, record)){
            maxlen = std::max(maxlen, record.name.size());
            students.push_back(record);
        }

        // order the students by name
        sort(students.begin(), students.end(), compare);

        // sort does not work on list because there is no random access possible (e.g. by index)
        // so list has its own implementation
        // std::list<Student_info> students;
        // students.sort(compare);

        std::vector<Student_info> failed;
        failed = iter_extract_failed(students);

        for (std::vector<Student_info>::const_iterator iter = failed.begin(); iter != failed.end(); ++iter){
            std::cout << "----------------------" << std::endl;
            std::cout << iter->name << std::endl;
        }

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
    }

    return 0;
}

std::vector<std::string> split_string_by_spaces(const std::string& s)
{
    std::vector<std::string> out;

    typedef std::string::size_type string_size;

    std::string::size_type i = 0;

    while (i != s.size()){
        while (i != s.size() && isspace(s[i]))
            ++i;

        string_size j = i;

        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j) {
            out.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return out;
}
