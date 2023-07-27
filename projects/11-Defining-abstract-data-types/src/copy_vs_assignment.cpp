#include <stdio.h>

class INT
{
    public:
        int m_value;

        INT() : m_value(0)
        {
            printf("Called empty constructor\n");
        };
        INT(int v) : m_value(v)
        {
            printf("Called 1 para constructor\n");
        };

        // Copy constructor
        INT(const INT& v)
        {
            printf("Called copy constructor\n");
            this->m_value = v.m_value;
        };

        // assignement op
        INT& operator=(const INT& rhs)
        {
            printf("Called assignment operator\n");
            this->m_value = rhs.m_value;
            return *this;
        };
};


void copy_vs_assignment()
{
    INT a = 1;
    printf("%d\n", a.m_value);
    INT b(2);
    printf("%d\n", b.m_value);
    INT c;
    printf("%d\n", c.m_value);

    c = a;      // calls assignement operator
    INT d = b;  // calls copy constructor
    INT e(c);   // calls copy constructor
}
