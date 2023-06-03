#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "median.hpp"
#include "data_structure_independence.hpp"
#include "iterators_for_flexibility.hpp"

int main(){
    std::cout << "HELLO" << std::endl;

    std::vector<int> v({0,2,3,4,5,2});
    std::vector<float> v2({0.2, 2.4,3.2,4.6,5,2.7});

    std::cout << median(v) << std::endl;
    std::cout << median(v2) << std::endl;

    // FIND
    {
        std::vector<int>::const_iterator it = fn(v.begin(), v.end(), 2);
        std::cout << *it << std::endl;
    }

    // COPY
    {
        std::vector<int> d;
        cp(v.begin(), v.end(), back_inserter(d));

        std::vector<int>::const_iterator tmp;
        for (std::vector<int>::const_iterator it = d.begin(); it != d.end(); ++it)
            std::cout << *it << "\t" << *it++ << std::endl;
    }

    // REPLACE
    {
        my_replace(v.begin(), v.end(), 3, 10);
    }

    // REVERSE
    {
        print(v);
        my_reverse(v.begin(), v.end());
        print(v);
    }
    {
        std::sort(v.begin(), v.end());
        print(v);
        bool out = my_binary_search(v.begin(), v.end(), 3);
        std::cout << out << std::endl;
    }

    // Input / output iterators
    // {
    //     std::vector<int> v;

    //     // read int from std input and append to v
    //     std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), back_inserter(v));
    //     print(v);

    //     // write to std out
    //     std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // }

    // Using iterators for flexibility
    {
        std::string s;
        std::vector<std::string> out;
        while (getline(std::cin, s))
            new_split(s, std::ostream_iterator<std::string>(std::cout, "\n"));
        // new_split(s, back_inserter(out));
        print(out);
    }



    return 0;
}
