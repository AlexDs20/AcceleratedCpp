#include <algorithm>
#include <vector>
#include <stdexcept>

// template header -> says we define a template function
// the function take a *type parameter* (similar to function parameter)
// -> define name that can be used within function scope
template <class T>
T median(std::vector<T> v){
    typedef typename std::vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");

    std::sort(v.begin(), v.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}
