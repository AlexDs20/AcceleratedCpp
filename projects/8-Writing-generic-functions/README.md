# 8 Writing generic functions
Functions with parameter types we do not know until we call the functions.

## Which types work in a generic function?
It checks if all the operations in the function are defined on the given parameters.
If not &rarr; crash.

## Template functions
- allow us to write a single function definition for a family of functions that behaves similarly.

### HOW TO
Example:

```c++
template <class T>
T median(std::vector<T> v){
    typedef typename std::vector<T>::size_type st;
    // DO STUFF
}
```

- template header:
```c++
template <class T>
```
- says we define a template function
- the function takes a *type parameter* (similar to function parameter)
- defines name that can be used within function scope: **T**

```c++
typename
```

- to tell the implementation that `std::vector<T>::size_type` is the name of a type
- MUST use when
    - have a type that depends on a template parameter e.g. std::vector<T> and want to access a member of it which is also a type

- the standard library knows that *std::vector<T>::size_type* is a type but not the implementation

## 8.2 Data-Structure independence
- Could also want to have functions that could handle *list*, *vector* or *string*.

- There are 5 iterator categories:
    - each correspond to a collection of iterator operations
    - standard-lib algo. says which category it expects

- Each category:
    - different strategy for accessing the container elements

### Access strategy: Sequential read-only access
Called **Input Iterator**

Access elements:
- read sequentially

```c++
template <class In, class X> In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
        ++begin;    // uses sequential access
    return begin;
}
```

Required operations:
- `begin++` and `++begin`
- `==` and `!=`
- `*`
- equivalence: `iter->member` and `(*it).member`

### Access strategy: Sequential write-only access
Called **Output Iterator**

```c++
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while(begin != end)
        *dest++ = *begin++;
    return dest;
}
```

Required operations:
- `*begin`
- `begin++` and `++begin`

### Access strategy: Sequential read-write access
Called **Forward Iterator**

- read and write but only sequentially

```c++
// replaces elements equals to x by y
template <class For, class X>
void replace(For begin, For end, const X& x, const X& y)
{
    while (begin != end)
    {
        if (*begin == x)
            *begin = y;
        ++begin;
    }
}
```

Needs to support:
- `*it` (for reading and writing)
- `++it` and `it++` (not *--* versions)
- `it==j` and `it!=j`
- `it->member` as synonym for `(*it).member`


### Access strategy: Reversible access
Called **bidirectional iterator**

```c++
template <class In>
void my_reverse(In begin, In end)
{
    while (begin != end){
        --end;
        if (begin != end)
            std::swap(*begin++, *end);
    }
}
```

- needs same as forward iterator
- also needs `--` support


### Access strategy: Random access
- Need to be able to jump around in container

Example:
    - binary-search algorithm


```c++
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        // mid point
        Ran mid = begin + (end - begin) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}
```

Relies on the ability to do arithmetic with iterators!

Requirements (p, q &rarr; iterators, n &rarr; int):
- bidirectional iterators
- *p+n*, *p-n*, and *n+p*
- *p-q* &rarr; integer
- *p[n]* (equivalent to *(p+n))
- *p<q*, *p>q*, *p<=q*, and *p>=q*


## 8.3 Input and output iterators

```c++
std::istream_iterator<int>(std::cin)
```

expects to read *int*s from standard input.
