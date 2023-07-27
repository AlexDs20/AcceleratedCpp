#include <iostream>

#include "vec.hpp"

#include "copy_constructor.hpp"
#include "copy_vs_assignment.hpp"

int main(int argc, char** argv)
{
    Vec<float> vec_default_const;
    Vec<float> vec_size_const(10);
    Vec<float> vec_size_init_const(10, 0.5f);

    std::cout << vec_default_const.size() << std::endl;
    std::cout << vec_size_const.size() << std::endl;
    std::cout << vec_size_init_const.size() << std::endl;


    // copy_constructor();
    // copy_vs_assignment();
    return 0;
}
