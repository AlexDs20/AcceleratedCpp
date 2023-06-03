#include <algorithm>
#include <string>


bool not_space(char c)
{
    return !isspace(c);
}

bool space(char c)
{
    return isspace(c);
}

template<class Out>
void new_split(const std::string& str, Out os)
{
    typedef std::string::const_iterator iter;

    iter i = str.begin();

    while (i != str.end()) {
        i = std::find_if(i, str.end(), not_space);

        iter j = std::find_if(i, str.end(), space);

        if (i != str.end())
            *os++ = std::string(i, j);

        i = j;
    }
}
