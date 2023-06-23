#include <iostream>

#include "vec.hpp"

#include "copy_constructor.hpp"

int main(int argc, char** argv)
{
    Vec<float> my_vec;
    Vec<float> my_float_vec(10, 0.5);

    copy_constructor();
    return 0;
}
