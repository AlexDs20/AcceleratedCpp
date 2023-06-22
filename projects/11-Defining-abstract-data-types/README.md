# Defining abstract data types
In this chapter we basically build the std::vector class.

Look in particular at copying, assigning and destroying.

When designing a class:
- start by designing interface we want the user to use


Want:
- `begin`, `end` and `size` functions &rarr; store addresses of first and 1 past last elements

The memory allocation should:
- not use `new T[n]` because:
    - it does not only *allocate* but also *initialize* &rarr; not general enough
    - the size is fixed and cannot add elements to the array (?)
- instead get more control using `<allocator>`:
    - allows to allocate in one step
    - build the objects in that memory in another memory


We want two **Constructors**:
- `Vec(){create();}`
    - allows to just allocate memory
- `explicit Vec(std::size_t n, const T& val=T()){create(n,val);}`
    - allows to allocate memory + construct n objects T, if T is not provided, use the object build using default constructor.
    - explicit:
        - only for constructors with 1 argument
        - compiler use constructor ONLY when the user explicitly invokes the constructor
        - i.e. specifies that it cannot be used for implicit conversions and copy-initialization

        - ```c++
            Vec<int> vi(100);       // explicit construction from an int
            Vec<int> vi = 100;      // error: implicit construct and copy to vi
          ```

We can add types to be able to have useful features such as `back_inserter` working.


Overloading index operator:
```c++
    T& operator[] (size_type i) { return data[i]; };
    const T& operator[] (size_type i) const { return data[i]; };
```
The first one allow to read and assign!

&rarr; Need for one for const object to not assign
