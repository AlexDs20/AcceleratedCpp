#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);

void gen_aux(const Grammar& g, const std::string& cat, std::vector<std::string>& sentence);

bool bracketed (const std::string&);
#endif
