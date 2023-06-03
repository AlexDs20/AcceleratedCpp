#ifndef ARRAY_AND_POINTERS_HPP
#define ARRAY_AND_POINTERS_HPP


// --------------------
void pointers();

// --------------------
// function pointers
void function_pointers();
int function_int(int);
int function_arg(int func(int), int);
int function_arg2(int (*func)(int), int);
typedef int (*func_ptr)(int);       // define type: func_ptr that is a pointer to function with int arg and returns int.
func_ptr get_function_ptr(int func(int));

// --------------------
void application();
template<class In, class Pred>
In my_find_if(In begin, In end, Pred f){
    while (begin != end && !f(*begin))
        ++begin;
    return begin;
};
bool is_neg(int);

// --------------------
void array_and_pointers();
void array();
void pointer_arithmetic();

void indexing_10_1_5();

#endif
