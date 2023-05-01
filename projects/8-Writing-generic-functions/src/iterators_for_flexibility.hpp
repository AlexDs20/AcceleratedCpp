#ifndef ITERATORS_FOR_FLEXIBILITY_HPP
#define ITERATORS_FOR_FLEXIBILITY_HPP

#include <string>

template<class Out>
void new_split(const std::string& str, Out os);

bool not_space(char c);
bool space(char c);

#include "iterators_for_flexibility.cpp"

#endif
