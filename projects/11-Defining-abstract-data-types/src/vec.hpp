#ifndef VEC_HPP
#define VEC_HPP

#include <cstddef>      // size_t


template <class T>
class Vec{
    public:     // interface
        // types
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef std::size_t size_type;
        // types for being able to use back_insterter that uses .push_back
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T& reference;
        typedef const T& const_reference;

        // Constructors
        Vec() { create(); }         // default constructor
        // explicit:
        //      only for constructors with 1 argument
        //      compiler use constructor ONLY when the user explicitly invokes the constructor
        //      i.e. specifies that it cannot be used for implicit conversions and copy-initialization
        //
        explicit Vec(std::size_t n, const T& val=T()) { create(n, val); }

        // Operations
        size_type size() const { return limit - data; };
        T& operator[] (size_type i) { return data[i]; };
        const T& operator[] (size_type i) const { return data[i]; };

        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return limit; }
        const_iterator end() const { return limit; }

    private:    // implementation
        iterator data;                    // first element in the Vec
        iterator limit;                   // one past the last element in the Vec

        void create(){};
};

#endif
