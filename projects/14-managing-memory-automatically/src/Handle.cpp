// Handle takes over the memory management for the object to which it is attached
// Attach one handle per object
//  After, should not access the object directly
#include <stdexcept>

template <class T>
class Handle {
public:
    Handle(): p(nullptr){}
    Handle(const Handle& s): p(0) {
        if (s.p) {
            p = s.p->clone();
        }
    }
    Handle& operator=(const Handle& s) {
        if (this != &s) {
            delete p;
            p = s.p ? s.p->clone(): nullptr;
        }
        return *this;
    }
    ~Handle() {delete p;}
    Handle(T* t): p(t) {}

    operator bool() const {return p;}

    T& operator*() const {
        if (p) {
            return *p;
        }
        throw std::runtime_error("unbound Handle!");
    }
    T* operator->() const {
        if (p) {
            return p;
        }
        throw std::runtime_error("unbound Handle!");
    }

private:
    T* p;
};


class Core {
public:
    Core(): v(0){};
    Core(int val): v(val) {};
// private:
    int v;
};

class Derived: public Core {
public:
    int w = 1;
};
