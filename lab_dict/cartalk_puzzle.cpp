/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of 
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector< StringTriple > cartalk_puzzle(PronounceDict d,
                                      const string& word_list_fname)
{
    vector <StringTriple> ret;
    std::fstream file;
    string word;
    vector<string> words;
    file.open(word_list_fname);

    if(file.is_open()) {
        while (file >> word) {
            words.push_back(word);
        }
    }
    for (auto & element: words) {
        if (element.length() <= 1) {
            continue;
        } else {
            string subStr1 = element.substr(1, element.length()-1);
            string subStr2 = element.substr(0, 1).append(element.substr(2, element.length()-2));
            if (d.homophones(element, subStr1) && d.homophones(element, subStr2) && d.homophones(subStr1, subStr2))
                ret.push_back({element, subStr1, subStr2});
        }
        
    }
    file.close();
    return ret;
}


