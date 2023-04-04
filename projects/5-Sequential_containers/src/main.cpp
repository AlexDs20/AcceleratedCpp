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
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string>::size_type width(const std::vector<std::string>& v);
std::vector<std::string> vconcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);
std::vector<std::string> hconcat(const std::vector<std::string>& left, const std::vector<std::string>& right);

int main()
{
    std::vector<Student_info> students;
    Student_info record;
    std::string::size_type maxlen = 0;

    std::string text = "This is a test.";
    std::vector<std::string> words = split_string_by_spaces(text);
    for (std::vector<std::string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
        std::cout << *iter << std::endl;

    // Example of framing
    std::vector<std::string> p = {
        "This is an",
        "example",
        "to",
        "illustrate",
        "framing",
    };

    std::vector<std::string> new_p = frame(p);
    p = vconcat(p, new_p);
    p = hconcat(p, frame(p));

    for (std::vector<std::string>::size_type i = 0; i != p.size(); ++i){
        std::cout << p[i] << std::endl;
    }

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

std::vector<std::string> vconcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom){
    std::vector<std::string> ret = top;

    // naive way of doing it
    for (std::vector<std::string>::const_iterator it = bottom.begin(); it!=bottom.end(); ++it)
        ret.push_back(*it);

    // alternative, use built-in insert
    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}

std::vector<std::string> hconcat(const std::vector<std::string>& left, const std::vector<std::string>& right){
    std::vector<std::string> ret;
    std::string::size_type w_left = width(left) + 1;
    std::string::size_type w_right = width(right);

    std::vector<std::string>::size_type maxrow = std::max(left.size(), right.size());

    for (std::vector<std::string>::size_type i = 0; i!= maxrow; ++i){
        std::string append(w_right, ' '), prepend(w_left, ' ');

        if (i < left.size())
            prepend = left[i] + std::string(w_left - left[i].size(), ' ');

        if (i < right.size())
            append = right[i] + std::string(w_right - right[i].size(), ' ');

        ret.push_back(prepend + append);
    }
    return ret;
}

std::vector<std::string>::size_type width(const std::vector<std::string>& v){
    std::vector<std::string>::size_type w = 0;
    std::vector<std::string>::size_type i;
    for (i = 0; i!= v.size(); ++i)
        w = std::max(w, v[i].size());
    return w;
}

std::vector<std::string> frame(const std::vector<std::string>& v) {
    typedef std::vector<std::string> vec_string;
    vec_string ret;
    vec_string::size_type w = width(v);
    std::string border(w + 4 , '*');

    ret.push_back(border);

    for(vec_string::size_type i = 0; i!= v.size(); ++i){
        ret.push_back("* " + v[i] + std::string(w - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);

    return ret;
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
