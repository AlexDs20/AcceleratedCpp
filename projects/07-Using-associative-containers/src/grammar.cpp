#include <stdexcept>
#include <string>
#include <vector>
#include <stdexcept>

#include "grammar.hpp"
#include "text_processing.hpp"
#include "random_number.hpp"

Grammar read_grammar(std::istream& in)
{
    // Here define how the same as in table page 129 with the categories and rules
    // It returns the grammar which maps some categories to rules
    Grammar ret;
    std::string line;

    while(getline(in, line)){
        std::vector<std::string> entries = split(line);

        if (!entries.empty())
            ret[entries[0]].push_back(
                    Rule(entries.begin() + 1, entries.end()));  // type(Rules): vector<string> -> built from iter.
    }
    return ret;
}

std::vector<std::string> gen_sentence(const Grammar& g){
    std::vector<std::string> ret;

    gen_aux(g, "<sentence>", ret);

    return ret;
}

void gen_aux(const Grammar& g, const std::string& key, std::vector<std::string>& sentence){

    // if the key is not within bracket -> not a key but an actual word
    if (!bracketed(key)){
        sentence.push_back(key);
    } else{
        // in principle we want to do:
        //  g[key] but if it does not exist -> the implementation automatically creates an element with that key -> no rule so we should actually throw error
        Grammar::const_iterator it = g.find(key);
        if (it == g.end())
            throw std::logic_error("empty rule");

        // get the list containing all the rule for that category
        const Rule_collection& c = it->second;

        // select one of the rule
        const Rule& r = c[nrand(c.size())];

        // go through each elements of that rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, sentence);
    }
}

bool bracketed (const std::string& word){
    return *(word.begin())=='<' && *(word.end()-1)=='>';
}
