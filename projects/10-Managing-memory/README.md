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
