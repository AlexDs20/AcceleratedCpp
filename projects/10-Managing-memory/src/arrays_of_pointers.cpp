#include <iostream>
#include <string>




std::string letter_grade(double grade){
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    if (false) {
        std::cout << letters << std::endl;
        std::cout << *letters << std::endl;
        std::cout << letters[0] << std::endl;
        std::cout << letters[1][0] << std::endl;
        std::cout << letters[2] << std::endl;
        std::cout << letters[2][0] << std::endl;
        std::cout << letters[2][1] << std::endl;
    }

    // sizeof -> result in bytes
    static const std::size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    std::cout << ngrades << std::endl;

    for (std::size_t i = 0; i < ngrades; ++i){
        if (grade >= numbers[i])
            return letters[i];
    }

    return "?\?\?";
};


void arrays_of_pointers(){
    double grade = 97;
    std::string letter = letter_grade(grade);
    std::cout << grade << " corresponds to: " << letter << std::endl;
};
