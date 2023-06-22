#ifndef VEC_HPP
#define VEC_HPP

#include <cstddef>      // size_t


template <class T>
class Vec{
    public:     // interface
        Vec() { create(); }         // default constructor

        // explicit:
        //      only for constructors with 1 argument
        //      compiler use constructor ONLY when the user explicitly invokes the constructor
        //      i.e. specifies that it cannot be used for implicit conversions and copy-initialization
        //
        explicit Vec(std::size_t n, const T& val=T()) { create(n, val); }

    private:    // implementation
        T* data;                    // first element in the Vec
        T* limit;                   // one past the last element in the Vec

        void create(){};
};

#endif
