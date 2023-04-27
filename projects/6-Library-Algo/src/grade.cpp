#include <algorithm>
#include <vector>
#include <list>
#include <stdexcept>

#include "grade.hpp"
#include "median.hpp"
#include "student_info.hpp"

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// vector<double>& -> creates a reference i.e. direct access to the argument without copy
// const vector<double>& -> assures that the content will not change -> constant
double grade(double midterm, double final, const std::vector<double>& hw)
{
    if (hw.size() == 0)
        throw std::domain_error("Student has done no homework!");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s){
    // the grade func on students throws an error if no homework are done.
    // we handle that error here by setting it to 0.
    //
    // it also solves the issue that when calling transform, now the function knows grade_aux as it is not overloaded
    // with just grade, that function is overloaded and the compiler does not know which one to call
    try {
        return grade(s);
    } catch (std::domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

bool pgrade(const Student_info& s){
    return !fgrade(s);
}

bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

bool did_all_hw(const Student_info& s){
    return (std::find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

std::vector<Student_info> single_pass_extract_fails(std::vector<Student_info>& students){
    // this method rearranges the students so that the passing students and failing students are grouped
    // it returns an iter. to the first element of the second category
    std::vector<Student_info>::iterator iter = std::stable_partition(students.begin(),
            students.end(), pgrade);
    std::vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}

std::vector<Student_info> two_pass_extract_fails(std::vector<Student_info>& students){
    std::vector<Student_info> fail;
    std::remove_copy_if(students.begin(), students.end(),
            back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade),
            students.end());
    return fail;
}

std::vector<Student_info> slow_extract_failed(std::vector<Student_info>& students){
    std::vector<Student_info> fail;
    std::vector<Student_info>::size_type i = 0;

    while (i != students.size())
    {
        if (fgrade(students[i])){
            fail.push_back(students[i]);
            students.erase(students.begin() + i);   // This erase is very slow because of having to recopy
        } else
            ++i;
    }
    return fail;
}

std::vector<Student_info> iter_extract_failed(std::vector<Student_info>& students){
    std::vector<Student_info> fail;
    std::vector<Student_info>::iterator iter = students.begin();

    // // const_iterator used as read_only
    // for (std::vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter){
    //     std::cout << (*iter).name << std::endl;     // dereference to access the current object (*iter) and access its member name
    //     std::cout << iter->name << std::endl;       // a shortcut
    // }

    while (iter != students.end()){
        if (fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }

    return fail;
}

std::list<Student_info> list_extract_failed(std::list<Student_info>& students){
    /*
    List works similarly as vector. Except that:
        - vector allow access to elements by index
        - vector are fast for iteration through elements sequentially
        - vector are slow for insert/delete in the middle
        - vector might be slow for push_back if there is no memory space available at the end of the vector
        - list do not allow element access by index
        - list allow for faster insert and erase of elements
    */
    std::list<Student_info> fail;
    std::list<Student_info>::iterator iter = students.begin();

    // in the case of list, the iterator following erases are not invalidated

    while (iter != students.end()){
        if (fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }

    return fail;
}
