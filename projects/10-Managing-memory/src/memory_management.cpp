#include <iostream>
#include <string>
#include "memory_management.hpp"


int* automatic_invalid_pointer(){
    int x = 42;
    return &x;
};

int* static_valid_pointer(){
    static int x = 42;
    return &x;
};

int* dynamic_valid_pointer(int value){
    // allocates an int object
    // object stays until program ends or run delete pointer
    int* pt = new int(value);
    return pt;
    // alternatively: return new int(value);
};


void dynamically_allocated(){
    int *pt1, *pt2;
    std::cout << "First call to dynamic allocation: " << std::endl;
    pt1 = dynamic_valid_pointer(42);
    std::cout << "Value at: " << pt1 << " is: " << *pt1 << " decrease by 1: " << --*pt1 << std::endl;

    std::cout << "Second call to dynamic allocation: " << std::endl;
    pt2 = dynamic_valid_pointer(43);
    std::cout << "Value at: " << pt2 << " is: " << *pt2 << std::endl;

    // Dynamically allocating requires that we clean ourselves the pointer
    delete pt1, pt2;
};


void statically_allocated(){
    int* pt = static_valid_pointer();
    std::cout << "Pointer pointing at: " << pt << std::endl;
    std::cout << "Value at: " << pt << " is: " << *pt << std::endl;
};

void automatic(){
    // allocates the memory automatically and assign value at variable's definition
    // deallocate at the end of the
    int* pt = automatic_invalid_pointer();
    // pt is a nullptr
    if (pt == nullptr)
        std::cout << "pt is a nullptr" << std::endl;
    // this segfaults
    // std::cout << *pt << std::endl;
};


void three_kinds_of_mem_management(){

    std::cout << "Automatically allocated: " << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    automatic();

    // Valid alternative to return memory allocated in function: statically allocated
    std::cout << "Statically allocated: " << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    statically_allocated();

    // If we want to return different address everytime we call the function:
    // use dynamic allocation instead of static
    std::cout << "Dynamically allocated: " << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    dynamically_allocated();
}
