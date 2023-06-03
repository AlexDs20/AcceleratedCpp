#include "generating_sentences.hpp"
#include "grammar.hpp"

void generating_sentences()
{
    // generate grammar
    Grammar grammar = read_grammar(std::cin);

    // generate a sentence
    std::vector<std::string> sentence =  gen_sentence(grammar);

    // write the sentence
    std::vector<std::string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        std::cout << *it;
        ++it;
    }
    while (it != sentence.end()) {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << "." << std::endl;
}
