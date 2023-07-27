#pragma once

#include <iostream>
#include <cstddef>      // size_t
#include <memory>


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
        Vec(){ create(); }         // default constructor -> data and limit set to nullptr
        // explicit:
        //      only for constructors with 1 argument
        //      compiler use constructor ONLY when the user explicitly invokes the constructor
        //      i.e. specifies that it cannot be used for implicit conversions and copy-initialization
        //
        explicit Vec(std::size_t n, const T& val=T()) { create(n, val); }

        // copy constructor used when:
        //      passing by value to function
        //      returning by value from function
        //      copy object to initialize a new object
        Vec(const Vec& v) { create(v.begin(), v.end()); };

        // Destructor
        ~Vec(){ uncreate(); };

        // Operators
        T& operator[] (size_type i) { return m_data[i]; };
        const T& operator[] (size_type i) const { return m_data[i]; };
        // Assignement operator
        //      defines what it means to assign one value of the class type to another
        //      difference with copy constructor is that here lhs already may have values -> destroy first
        //
        //      Within scope of template, can return Vec and not Vec<T>
        Vec& operator= (const Vec& rhs);

        size_type size() const { return m_available - m_data; };

        iterator begin() { return m_data; }
        const_iterator begin() const { return m_data; }

        iterator end() { return m_available; }
        const_iterator end() const { return m_available; }

        void push_back(const T& val)
        {
            if (m_available == m_limit)
                grow();
            unchecked_append(val);
        };

    private:    // implementation
        iterator m_data;                    // first element in the Vec
        iterator m_available;               // one past the last element in the Vec -> i.e. first available
        iterator m_limit;                   // one past the last available allocated memory

        std::allocator<T> m_alloc;

        void create();
        void create(std::size_t n, const T& val);
        void create(const_iterator begin, const_iterator end);

        void uncreate();

        void grow();
        void unchecked_append(const T& val);
};


template <class T>
void Vec<T>::create()
{
    m_data = m_available = m_limit = nullptr;
}

template <class T>
void Vec<T>::create(std::size_t n, const T& val)
{
    m_data = m_alloc.allocate(n);
    m_limit = m_available = m_data + n;
    std::uninitialized_fill(m_data, m_available, val);
}

template <class T>
void Vec<T>::create(const_iterator begin, const_iterator end)
{
    m_data = m_alloc.allocate(end - begin);
    m_limit = m_available = std::uninitialized_copy(begin, end, m_data);
}

template <class T>
void Vec<T>::uncreate()
{
    if (m_data)
    {
        iterator it = m_available;
        while (m_data != it)
            m_alloc.destroy(--it);

        m_alloc.deallocate(m_data, m_limit - m_data);
    }
    m_data = m_limit = m_available = nullptr;
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    // first check that we are not self-assigning
    if (this != &rhs) {
        // free already present data
        uncreate();

        // copy elements
        create(rhs.begin(), rhs.end());
    }
    return *this;
};

template <class T>
void Vec<T>::grow()
{
    size_type new_size = max(2 * (m_limit - m_data), ptrdiff_t(1));

    iterator new_data = m_alloc.allocate(new_size);
    iterator new_available = std::uninitialized_copy(m_data, m_available, new_data);

    uncreate();

    m_data = new_data;
    m_available = new_available;
    m_limit = m_data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val)
{
    m_alloc.construct(m_available++, val);
}
