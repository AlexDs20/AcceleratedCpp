#include <vector>
#include <stdexcept>
#include <algorithm>

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
