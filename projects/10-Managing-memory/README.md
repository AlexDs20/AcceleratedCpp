# Managing memory and low-level data structures
Start with arrays and pointers.
Then see how it combine with *new* and *delete* expressions

# Arrays and pointers
Array:
- kind of container like vector but less powerful

Pointer:
- kind of random access iterator used to access elements of arrays


## Pointers
- value that represents the address of an object
- If **x** is an object &rarr; **&amp;x** is the address of the object.
- If **p** is the address of an object &rarr; **\*p** is the object


**&amp;** is the address operator.


**\*** is the dereference operator.


If **p** contains the address of **x** &rarr; *p* points to *x*.

```c++
int x;
int *p;         // *p is of type int -> p is pointer to int
```

Here **\*p** is declarator

- Often initialize a pointer to the value 0

```c++
int a = 5;
int* b = nullptr;
b = &a;
```

alternatively

```c++
int a = 5;
int* b = &a;
```

NOTE:
```c++
int* p, q;
```
&rarr; p is a pointer to int but q is just a normal int!

```c++
int *p, q;
```
makes it clearer that *p* points to * \\*p * which is an *int*

### Pointers to functions
Pass a function as argument to another function
- The compiler translates it to use pointers to functions
- Work same as other pointers
- Only thing can do once dereferenced:
    - call the function
    - take the functions' address

Syntax:
```c++
int (*fp)(int);
```
- If we dereference **fp** and call it with an int argument &rarr; return int.
- **fp** is a pointer to a function that takes an int and returns an int.

Because with function you can only call or take the address:
- Anything with a function that is not a call returns the address


If we write a function that looks like it takes another function as a parameter:
```c++
int function1( int function2(int), int i );
```

What the compiler does is interpret **function2** to be a pointer instead.
So it could have been written as:
```c++
int function1( int (*function2)(int), int i );
```


Automatic translation does not apply to return values from functions (if we want to return a function pointer).
In that case we must say explicitly that we want to return a pointer.

Define a type: *function_fp* which is a pointer to a function (here that takes an int)
```c++
typedef int (*function_fp(int))
```
Then can define a function that returns a pointer to a func.

```c++
typedef int (*function_fp(int))
function_fp get_function_ptr();
```

## Arrays
- kind of container part of core language
- contain sequence of one or more objects of the same type
- Number of elements must be known at compile time
- Not class types &rarr; no members (such as *size_type*)
    - use **size_t** from *<cstddef>* instead
    - use **size_t** to deal with size of container

- When use name of array as value, the name is a pointer to the first element of the array
```c++
double c[3];
*c = 1.5;    // sets the value of c[0] to 1.5
```

## Pointer Arithmetic

if pointer *p* points to m
- &rarr; *(p+n)* points to *m+n*
- &rarr; *(p-n)* points to *m-n*

## Indexing
if point *p* points to element m in an array
- &rarr; p[1] points to m+1
- &rarr; p[-1] points to m-1

## Array initialization
Is easy compared to containers in the std lib.

```c++
const int month_lengths[]= {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};
```

# String literals
A string literal is an array of const char with one more element.
```c++
const char hello[] = {
        'H', 'e', 'l', 'l', 'o', '\0'
};
```
has the same properties as "Hello".

- '\0': null character used to mark then end

## Arrays of character pointers
We can initialize an array of charachter pointers by giving a sequence of string literals:
```c++
static const char* const letters[] = {
    "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
};
```
Which is an array of constant pointers to constant string literals.

## Arguments to main
Can access the number of inputs and the inputs to the main function.
`argv` is pointer of pointers
```c++
int main(int argv, char** argv){
for (int i=0; i<argv; ++i)
    std::cout << argv[i] << std::endl;      // argv[i] is a char*
}
```

## Reading and writing files
Can write standard error `std::cerr` and log `std::clog`.
Both output to standard error stream.

- `std::cerr`: writes directly &rarr; high overhead, use for errors
- `std::clog` buffers the data and writes whenever &rarr; faster if don't need to get the output directly, use for logging


### Using files
To use files, need to create objects of type `ifstream` and `ofstream`.

Very similiar to `istream` and `ostream`.
Can use an *ifstream* whenever an *istream* is expected. Similar with outputs.

```c++
#include <fstream>
int main(){
    std::ifstream infile("infile");
    std::ofstream outfile("outfile");
    std::string s;
    while (std::getline(infile, s))
        outfile << s << std::endl;
}
```
