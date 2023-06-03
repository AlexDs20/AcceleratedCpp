#ifndef DATA_STRUCTURE_INDEP_HPP
#define DATA_STRUCTURE_INDEP_HPP


template <class Ran, class X>
bool my_binary_search(Ran begin, Ran end, const X& x);

// reverse
template <class In>
void my_reverse(In begin, In end);

// replace
template <class For, class X>
void my_replace(For begin, For end, const X& x, const X& y);

// find
template <class In, class X>
In fn(In begin, In end, const X& x);

// copy
template <class In, class Out>
Out cp(In begin, In end, Out dest);

#include "data_structure_independence.cpp"

#endif
