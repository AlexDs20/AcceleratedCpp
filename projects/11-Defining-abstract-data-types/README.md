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


## Copy control
We need to define what happens when objects are copied, assigned or destroyed.

If we don't provide it, the compiler will synthesize them, can be good, can be bad.

### Copy constructor

- when pass object by value
- when returning object by value
```c++
    int vi;
    void_function_call(vi);                 // implicit copy vi into the parameters
    int ret = return_function_call(vi);     // implicit copy the returned value in ret
```
- when explicitly initializing from another object
```c++
    vector<int> v1;
    vector<int> v2 = v1;                    // explicit copy
```

Handled by copy constructor. Important that the parameter is a reference!
```c++
    template <class T>
    class Vec {
        public:
            Vec(const Vec& v);              // copy constructor
    };
```
Note that this copy constructor should "copy".

E.g. we should not copy a pointer (i.e. the address where the data is) but we should copy the content and point to the copied content.

### Assignment operator
- when take a const ref to the class
```c++
class Vec {
    public:
        Vec& operator=(const Vec&);
};
Vec v1;
Vec v2;
v2 = v1;
```
- return type is reference to the left-hand side

For assignment, often **must** obliterate existing value of the left-hand side (not the case of the copy constructor).

#### member function outside of a class
```c++
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    // check for self assign
    if (&rhs != this) {
        obliterate();

        // Copy elements
        create(rhs);
    }
}
```
#### *this* keyword
- *this* only accessible in member function
- pointer to the current object
- bound to the left operand

### Assignment is not initialization
- Assignment always obliterates a previous value
- Initialization never does:
-   - Creates a new object and gives it a value at the same time

Initialization happens:
- variable declaration
- function parameters on entry to a function
- return value of a function when returning
- in constructor initializers

```c++
    string url_ch = "~;/?:@=&$-_.+!*’(),";  // initialization
    string spaces(url_ch.size(), ’ ’);      // initialization
    string y;                               // initialization
    y = url_ch;                             // assignment


    vector<string> split(const string&);    // function declaration
    vector<string> v;                       // initialization
    v = split(line);            // on entry, initialization of split’s parameter from line;
                                // on exit, both initialization of the return value
                                // and assignment to v
```

### Destructor
- What happens when object of class is destroyed
- Should do all the cleanup such as releasing memory
```c++
    template <class T>
    class Vec
    {
        public:
            Vec();              // default constructor
            ~Vec();             // destructor
    };
```

- Typically, if the class needs a destructor (typically because we need to free memory), it needs a copy constructor and assignment operator

### CAREFUL
- If no constructor is provided the compiler synthesizes one
- If no destructor or copy constructor, compiler synthesizes one. It may be wrong if dynamically allocates memory!
- We do not want two objects with points pointing to the same memory!

## Memory allocation
- Using `new` initializes but we don't want that because:
    - stuff will be initialized twice.
    - when doubling the memory to contain more elements, the elements would be initialized but maybe never used.

- Instead use the `<memory>` header:
    - contains the `allocator<T>` class which can:
        - allocate and without initialization
        - provides pointer to `<T>` but empty... &rarr; dangerous!
        - useful functions/member functions
        ```c++
        template <class T> class allocator {
        public:
            T* allocate(size_t);            // Allocates, uninitialized storage
            void deallocate(T*, size_t);    // Frees the uninitialized storage from allocate
            void construct(T*, const T&);   // Construct/initializes an object in the uninitialized storage
            void destroy(T*);               // Destroys the object, runs the destructor for T making the storage uninitialized
        };
        template <class In, class For> For uninitialized_copy(In, In, For);             // copy elements from the sequence of the first 2 arguments (e.g. begin(), end()) into the third.
        template <class For, class T> void uninitialized_fill(For, For, const T&);      // fill the space between the first two arguments with copies of the third argument
        ```
