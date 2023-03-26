#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";

    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";
    std::cout << std::endl;

    const int pad = 3;
    const int rows = 2 * pad + 3;

    const std::string::size_type cols = greeting.size() + 2 * pad + 2;

    for (int r = 0; r != rows; ++r) {
        std::string::size_type c = 0;
        while (c != cols){
            if (r == 0 || r == rows - 1 || c == 0 || c == cols -1){
                std::cout << "*";
                ++c;
            } else {
                if (r == pad + 1 && c == pad + 1){
                    std::cout << greeting;
                    c += greeting.size();
                } else {
                    std::cout << " ";
                    ++c;
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
