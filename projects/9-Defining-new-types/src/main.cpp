#include <iostream>
#include <string>
#include <vector>


template<class T>
void print(const T& t){
    typename T::const_iterator it = t.begin();
    std::cout << *it++;

    while (it != t.end())
        std::cout << ", " << *it++;
    std::cout << std::endl;
}


int main()
{
    std::vector<int> v({0,1,2,3,4,2,3,1,2});
    print(v);
    std::string v2("HELLO");
    print(v2);
    return 0;
}
