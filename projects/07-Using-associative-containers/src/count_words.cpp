#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "count_words.hpp"
#include "text_processing.hpp"


void count_words()
{
    std::string s;
    std::map<std::string, int> counters;

    // read and keep track of how many times each word was seen
    while (std::cin >> s)
        ++counters[s];

    // print it
    for (std::map<std::string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
        // access via *first* and *second* because it is using the *pair* data structure
        std::cout << (*it).first << "\t" << it->second << std::endl;
}


std::map< std::string, std::vector<int> > xref(
        std::istream& in,
        std::vector<std::string> find_words(const std::string&) = split)
{
    // Read one line at a time from cin
    // From that line identify the desired thing given by find_words function
    // Keep track that the line had the desired information
    std::map< std::string, std::vector<int> > ret;

    // read one line from cin
    std::string line;
    int line_number = 0;

    while (getline(in, line)) {
        ++line_number;
        std::vector<std::string> words = find_words(line);

        for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    return ret;
}


void cross_reference_table()
{
    // Want to know where the words occurred
    std::map<std::string, std::vector<int> > cross_ref = xref(std::cin);

    // Present the results
    for (std::map<std::string, std::vector<int> >::const_iterator it = cross_ref.begin();
            it != cross_ref.end(); ++it){
        std::cout << it->first << " occurs on line(s): ";

        // Now we split the lines we write so that we can add the , between the numbers
        std::vector<int>::const_iterator vit = (*it).second.begin();
        std::cout << *vit;
        ++vit;

        while (vit != it->second.end()){
            std::cout << ", " << *vit;
            ++vit;
        }
        std::cout << std::endl;
    }
}
