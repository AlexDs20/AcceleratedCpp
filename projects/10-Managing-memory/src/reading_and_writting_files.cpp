#include <fstream>
#include <string>
#include <iostream>

#include "reading_and_writting_files.hpp"

void read_and_write_files(){
    std::string file("../projects/10-Managing-memory/src/main.cpp");
    std::ifstream infile(file.c_str());
    std::ofstream outfile("/tmp/outfile.cpp");
    std::string s;
    while (std::getline(infile, s))
        outfile << s << std::endl;
}

void standard_error_stream(){
    std::cout << "Before error" << std::endl;
    std::cerr << "ERROR" << std::endl;      // output directly
    std::cout << "After error" << std::endl;
    std::clog << "LOG" << std::endl;        // also output in standard error but different buffering (faster)
};


void reading_and_writting_files(){
    // standard_error_stream();
    read_and_write_files();
};
