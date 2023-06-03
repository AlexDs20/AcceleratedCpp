#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

// When creating a function like this, we copy the content into vec
double median(std::vector<double> vec){
    // define a new name for the type of std::vector<double>::size_type
    typedef std::vector<double>::size_type vec_sz;

    vec_sz size = vec.size();

    if (size == 0)
        throw std::domain_error("Median of an empty vector.");

    std::sort(vec.begin(), vec.end());

    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
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

// read homework grades from an input stream into a vector<double>
std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
    if (in) {
        // start by clearing anything that may already be in hw
        hw.clear();

        std::cout << "Enter homework results: ";

        double x;
        while(in >> x)
            hw.push_back(x);

        // When we stop being able to read -> set the state as failure, thus reading will fail the next time we try.
        // Reset so that next time we do std::cin, it works
        in.clear();
    }

    return in;
}
