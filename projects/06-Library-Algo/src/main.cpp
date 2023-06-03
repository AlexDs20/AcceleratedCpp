#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <cctype>   // contains isspace

#include "grade.hpp"
#include "student_info.hpp"
#include "process.hpp"

std::vector<std::string> split_string_by_spaces(const std::string&);
std::vector<std::string> split(const std::string&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string>::size_type width(const std::vector<std::string>& v);
std::vector<std::string> vconcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);
std::vector<std::string> hconcat(const std::vector<std::string>& left, const std::vector<std::string>& right);
bool is_palindrome(const std::string&);
std::vector<std::string> find_urls(const std::string& s);
std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e);
std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e);
bool not_url_char(char c);
void side_stuff();

int main()
{
    // side_stuff();

    if (true) {
        std::vector<Student_info> students;
        Student_info record;
        std::string::size_type maxlen = 0;

        // list of students who did all the homework and those who didnt
        std::vector<Student_info> did, didnt;

        while(read(std::cin, record)){
            maxlen = std::max(maxlen, record.name.size());
            if (did_all_hw(record))
                did.push_back(record);
            else
                didnt.push_back(record);
            // also keep all the studens so the previous code does not break
            students.push_back(record);
        }

        // check that some students did all and some students didnt do all the homework
        if (did.empty()) {
            std::cout << "No students did all hw!" << std::endl;
            return 1;
        }
        if (didnt.empty()) {
            std::cout << "Every students did all hw!" << std::endl;
            return 1;
        }

        process_records(did, didnt);

        // order the students by name
        sort(students.begin(), students.end(), compare);

        // sort does not work on list because there is no random access possible (e.g. by index)
        // so list has its own implementation
        // std::list<Student_info> students;
        // students.sort(compare);

        std::vector<Student_info> failed;
        failed = iter_extract_failed(students);

        for (std::vector<Student_info>::const_iterator iter = failed.begin(); iter != failed.end(); ++iter){
            std::cout << "----------------------" << std::endl;
            std::cout << iter->name << std::endl;
        }

        //
        for (std::vector<Student_info>::size_type i = 0;
             i != students.size(); ++i) {

            // Write the name and pad with spaces
            std::cout << students[i].name
                << std::string(maxlen + 1 - students[i].name.size(), ' ');

            // compute and write the grade
            try {
                double final_grade = grade(students[i]);
                std::streamsize prec = std::cout.precision();
                std::cout << std::setprecision(3) << final_grade
                    << std::setprecision(prec);
            } catch (std::domain_error e){
                std::cout << e.what();
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

void side_stuff() {
    std::string url = "asdfqf sdfq http://HELLOW.com"
        " and another one https://anotherone.com";
    std::vector<std::string> url_list;
    url_list = find_urls(url);
    for (std::vector<std::string>::size_type i = 0; i!=url_list.size(); ++i)
        std::cout << url_list[i] << std::endl;

    std::string text = "This is a test.";
    std::vector<std::string> words = split_string_by_spaces(text);
    words = split(text);
    for (std::vector<std::string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
        std::cout << *iter << std::endl;


    // Example of framing
    std::vector<std::string> p = {
        "This is an",
        "example",
        "to",
        "illustrate",
        "framing",
    };

    std::vector<std::string> new_p = frame(p);
    p = vconcat(p, new_p);
    p = hconcat(p, frame(p));

    for (std::vector<std::string>::size_type i = 0; i != p.size(); ++i){
        std::cout << p[i] << std::endl;
    }
}

std::vector<std::string> vconcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom){
    std::vector<std::string> ret = top;

    // // naive way of doing it
    // for (std::vector<std::string>::const_iterator it = bottom.begin(); it!=bottom.end(); ++it)
    //     ret.push_back(*it);

    // // alternative, use built-in insert
    // ret.insert(ret.end(), bottom.begin(), bottom.end());

    // or use built-in library algo: copy
    // back_inserter produces an iterator from the ret container with good properties
    // it allows to copy the data from bottom.begin() to bottom.end() at the end of return
    copy(bottom.begin(), bottom.end(), back_inserter(ret));


    return ret;
}

std::vector<std::string> hconcat(const std::vector<std::string>& left, const std::vector<std::string>& right){
    std::vector<std::string> ret;
    std::string::size_type w_left = width(left) + 1;
    std::string::size_type w_right = width(right);

    std::vector<std::string>::size_type maxrow = std::max(left.size(), right.size());

    for (std::vector<std::string>::size_type i = 0; i!= maxrow; ++i){
        std::string append(w_right, ' '), prepend(w_left, ' ');

        if (i < left.size())
            prepend = left[i] + std::string(w_left - left[i].size(), ' ');

        if (i < right.size())
            append = right[i] + std::string(w_right - right[i].size(), ' ');

        ret.push_back(prepend + append);
    }
    return ret;
}

std::vector<std::string>::size_type width(const std::vector<std::string>& v){
    std::vector<std::string>::size_type w = 0;
    std::vector<std::string>::size_type i;
    for (i = 0; i!= v.size(); ++i)
        w = std::max(w, v[i].size());
    return w;
}

std::vector<std::string> frame(const std::vector<std::string>& v) {
    typedef std::vector<std::string> vec_string;
    vec_string ret;
    vec_string::size_type w = width(v);
    std::string border(w + 4 , '*');

    ret.push_back(border);

    for(vec_string::size_type i = 0; i!= v.size(); ++i){
        ret.push_back("* " + v[i] + std::string(w - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);

    return ret;
}

inline bool space(char c) {
    return isspace(c);
}

inline bool not_space(char c) {
    return !isspace(c);
}

std::vector<std::string> split(const std::string& str) {
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        if (i != str.end())
            ret.push_back(std::string(i, j));
        i = j;
    }
    return ret;
}

std::vector<std::string> split_string_by_spaces(const std::string& s) {
    std::vector<std::string> out;

    typedef std::string::size_type string_size;

    string_size i = 0;

    while (i != s.size()){
        while (i != s.size() && isspace(s[i]))
            ++i;

        string_size j = i;

        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j) {
            out.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return out;
}

bool is_palindrome(const std::string& s){
    // .rbegin returns an iterator that starts with the last element
    // equal assumes that the two sequences are the same length and thus no end is needed for the second sequence starting with .rbegin
    return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c){
    // returns true when c cannot be in URL
    //
    static const std::string url_ch = "~;/?:@=&$-_.+!*´";

    // check if c can be in URL, return the negative
    return !(isalnum(c)         // Can be a normal alpha numeric
            || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());      // if c is not in there -> find returns url_ch.end()
}

std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e){
    static const std::string sep = "://";
    typedef std::string::const_iterator iter;

    // i: where the iterator is found
    iter i = b;

    while ( (i = search(i, e, sep.begin(), sep.end())) != e ) {
        // make sure :// is not at the very begining or very end of string
        if (i != b && i + sep.size() != e) {
            // go back to get the protocole name (http)
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // check that it is valid (at least 1 character before and 1 after)
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        i += sep.size();
    }
    return e;
}

std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e){
    return find_if(b, e, not_url_char);
}

std::vector<std::string> find_urls(const std::string& s){
    // protocole-name://resource-name
    // Search for :// then look before for the protocol-name and after for the resource-name
    std::vector<std::string> ret;

    typedef std::string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    while (b != e){
        // loop for letters followed by ://
        b = url_beg(b, e);

        // If we find something
        if (b != e) {
            // Get the rest of URL
            iter after = url_end(b, e);

            ret.push_back(std::string(b, after));

            b = after;
        }
    }
    return ret;
}
