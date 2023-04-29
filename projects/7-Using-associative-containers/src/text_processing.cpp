#include <vector>
#include <string>
#include <algorithm>

#include "text_processing.hpp"


std::vector<std::string> split(const std::string& text){
    std::vector<std::string> ret;

    typedef std::string::const_iterator iter;

    iter i = text.begin();
    while (i != text.end())
    {
        i = std::find_if(i, text.end(), not_space);

        // find the end by finding the following space
        iter j = std::find_if(i, text.end(), space);

        if (i != text.end())
            ret.push_back(std::string(i, j));
        i = j;
    }
    return ret;
}

bool not_space(char c){
    return !isspace(c);
}

bool space(char c){
    return isspace(c);
}
