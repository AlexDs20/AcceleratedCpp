# 10 Memory management

- array is similar to vector but less powerful
- pointer is kind of random-access iterator
    - &rarr; to access array elements


## Pointers
- Represents the address of an object

- x is an object &rarr; &x is the address
    - `&` is the address operator
- p is the address &rarr; *p is the object
    - `*` is the dereference operator

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
.


## Arrays
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
