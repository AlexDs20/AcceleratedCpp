#include <cstdlib>
#include <stdexcept>
#include "random_number.hpp"


int nrand(int n){
    // split the max range into smaller buckets
    // some values in the end might not end up in any buckets.
    // then when sampling rand():
    // bucket:
    //      0 -> if rand() between [0, bucket_size),
    //      1 -> if rand() between [bucket_size, 2*bucket_size),
    //      2 -> if rand() between [2*bucket_size, 3*bucket_size),
    //      In the end, there may be some points between n*bucket_size and RAND_MAX, those are ignored
    //
    // Doing this, each bucket has the same size and because sampled initially from uniform, still uniform distrib.
    if (n <= 0 || n > RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range");

    // This should probably be RAND_MAX+1 but that doesn't work because of overflow
    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}
