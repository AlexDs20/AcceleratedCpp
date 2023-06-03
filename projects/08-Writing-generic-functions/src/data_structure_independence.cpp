#include <iostream>
#include <algorithm>


template <class Ran, class X>
bool my_binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        // mid point
        Ran mid = begin + (end - begin) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}


template <class In>
void my_reverse(In begin, In end)
{
    while (begin != end){
        --end;
        if (begin != end)
            std::swap(*begin++, *end);
    }
}


template <class For, class X>
void my_replace(For begin, For end, const X& x, const X& y)
{
    while (begin != end)
    {
        if (*begin == x)
            *begin = y;
        ++begin;
    }
}

template <class In, class X>
In fn(In begin, In end, const X& x){
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}


template <class In, class Out>
Out cp(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template <class T>
void print(const T& t)
{
    typename T::const_iterator beg = t.begin();
    std::cout << *beg++;
    for (typename T::const_iterator it = beg;
            it != t.end(); ++it)
        std::cout << ", " << *it;
    std::cout << std::endl;
}
