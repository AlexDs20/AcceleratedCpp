#include <iostream>


void pointers();
void function_pointers();
int function_int(int);
int function_arg(int func(int), int);
int function_arg2(int (*func)(int), int);


int main()
{
    // pointers();
    function_pointers();
}

void pointers(){
    std::cout << "POINTERS" << std::endl;
    int *q;
    std::cout << q << std::endl;
    if (q == nullptr)
        std::cout << "q is a nullptr" << std::endl;


    int *p, a;

    p = &a;         // could've written: int* p = &a;
    a = 4;

    std::cout << "int *p, a;" << std::endl;
    std::cout << "p is a pointer " << p << " to an int: " << *p << std::endl;
    std::cout << "a is an int: " << a << " with address " << &a << std::endl;

    // Change the value of a through p
    *p = 5;
    std::cout << "a now has the value: " << a << std::endl;

    std::cout << p << " " << p+1 << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
};

void function_pointers(){
    std::cout << "FUNCTION POINTERS" << std::endl;

    // A pointer to a function that takes an int and returns an int
    int (*fp)(int);

    // make fp point to function, the 2 are equivallent because we do not call the function -> get address
    fp = &function_int;
    fp = function_int;

    // Can call the function using the pointer, both return 9 because we make a call and do not access address
    std::cout << (*fp)(8) << std::endl;
    std::cout << fp(8) << std::endl;

    int out = function_arg(function_int, 8);
    std::cout << out << std::endl;

    out = function_arg(function_int, 8);
    std::cout << out << std::endl;
};

int function_int(int i){
    return i+1;
};

int function_arg(int func(int), int i){
    return func(i);
};
int function_arg2(int (*func)(int), int i){
    return func(i);
};
