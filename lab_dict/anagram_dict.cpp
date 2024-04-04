/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/** 
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */ 
AnagramDict::AnagramDict(const string& filename)
{
    std::fstream file;
    string word;
    vector<string> words;
    file.open(filename);

    if(file.is_open()) {
        while (file >> word) {
            words.push_back(word);
        }
    }
    file.close();
    *this = AnagramDict(words);
}

/** 
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */ 
AnagramDict::AnagramDict(const vector<string>& words)
{
    for (auto & element: words) {
        string str = element;
        sort(str.begin(), str.end());
        if (std::find(dict[str].begin(), dict[str].end(), element) == dict[str].end())
            dict[str].push_back(element);
    }

    auto tmpMap = dict;
    for (auto & element: tmpMap) {
        if (element.second.size() == 1) {
            auto it = dict.find(element.first);
            dict.erase(it);
        }
    }
}

/**
 * @param word The word to find anagrams of. 
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the 
 * word list.
 */
vector< string > AnagramDict::get_anagrams(const string& word) const
{
    vector<string> ret;
    string str = word;
    sort(str.begin(), str.end());

    for (auto & element : dict) {
        if (element.first == str){
            ret = element.second;
        }
    }
    
    return ret;
}       

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector< vector< string > > AnagramDict::get_all_anagrams() const
{
    vector<vector<string>> ret;
    for (auto & element : dict) {
        ret.push_back(element.second);
    }
    return ret;
}


