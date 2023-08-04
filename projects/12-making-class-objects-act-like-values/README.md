# Making class objects act like values
- In addition to copy control and assignment control &rarr; can also have support for automatic conversion between types
- For example the `std::string` class.
- We will implement something similar to it: `Str`


Member function or not?
- Member function if it affects the state

## Constructors
```c++
class Str {
public:
    Str(){};
    Str(size_type n, char c): data(n, c) {}

    Str(const char* cp);

    template <class In>
    Str(In b, In e);
}
```

- If we create one constructor, the compiler DOES NOT synthesize a default constructor
    - So we make it ourselves
- No copy constructor, assignement operator or destructor because:
    - We do not need a destructore so typically, the synthethized copy constructor and assignement operator are usually correct


## Automatic conversion
2 Types:
- from another type &rarr; Str
- from Str &rarr; another type

### Another type &rarr; Str
- Is handled by the constructor automatically when needed i.e.
```c++
    Str operator+(const Str& lhs, const Str& rhs);
```
works if called:
```c++
    this_is_a_Str + "string literal";
```
because there is a constructor to automatically do the conversion.
However this is somewhat inefficient because it it does
```c++
    Str temp1("string literal")
    Str temp2 = this_is_a_Str + temp1;
```
So it needs to initializes temporary variables. Slow if done often. In that case, better to do a specific implementation per type instead of automatically do the conversion.
- NOTE that this DOES NOT apply to the constructors that are `explicit`
    - Think hard here! Not making something `explicit` can have bad effect.
    - Typically make explicit the constructors that do not just construct directly from the input but instead define the "structure" of the object constructed
    - For example, if the following constructor:
    ```c++
    explicit Str(size_type n, char c='c'): data(n, c) {}
    ```
    Would have to be explicit otherwise:
    ```c++
    Str my_string("Hi")
    my_string + 4;      // compiles and gives: Hicccc
    ```
    Which is not a desired behaviour. But we don't need because we don't give a default value to `char c`

- If a class **support type conversion**, it is good to define binary operators as **nonmember functions**
    - If member function, the left operator cannot be automatically converted to the class, so the operation does not work and needs another def.
    - For assignment operator, we want to force left operand to be of class type &rarr; member function

### Str &rarr; another type
We can define a way to convert to other types
```c++
class Str {
public:
    operator double() const {};
}
```

## Output operator
To use:
```c++
    Str my_string("my Str");
    std::cout << my_string << std::endl;
```
We need to overload `operator<<`.
BUT it's a binary operator and on the LHS it is the *ostream* operator, note the *Str*.
- Thus we don't make it a member function.

```c++
std::ostream& operator<<(std::ostream& os, const Str& s) {
    for (Str::size_type i = 0; i!=s.size(); ++i)
        os << s[i];
    return os;
}
```

## Input operator
- Similar to output BUT we need to be able to write to the `data` that is a private member of `Str`.
- A non-member function does not work as is!
- Solution:
    - Use `friend` keyword
    - It allows the function to have access to the private members
```c++
class Str {
    friend std::istream& operator>>(std::istream& is, Str& s);      // declaration can be anywhere as it has access to private also
    public:
        // ...
    private:
        std::vector<char> data;
}

std::istream& operator>>(std::istream& is, Str& s) {
    // Implementation allow s.data though data is private
}
```

## Other stuff
- `void*` is a pointer that can point to any type but cannot be dereferenced
