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
makes it clearer.
