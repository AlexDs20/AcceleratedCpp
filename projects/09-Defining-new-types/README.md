# 9 Defining new types
## Member functions

```c++
struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream& read(std::istream&);
    double grade() const;       // the const here says that we will not change any of the data member
                                // compared to previous double grade(const Student_info& s);
                                // serves the same purpose as const Student_info&
                                // *const member function*
                                // cannot call nonconst member on a const object
}
```

Default protection:
- *struct*: public
- *class*: private

## Accessor functions


```c++
class Student_info {
    public:
        double grade() const;
        std::istream& read(std::istream&);
        std::string name() const {return n;};      // defined in class definition so that compiler can optimize and expand to *inline* if possible.

    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
}
```

- *name*: is an accessor function.
