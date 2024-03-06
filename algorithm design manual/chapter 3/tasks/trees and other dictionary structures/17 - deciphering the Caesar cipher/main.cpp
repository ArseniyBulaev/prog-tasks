#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>


std::unordered_map<char, int> generate_english_alphabet(){
    std::unordered_map<char, int> alphabet;
    for(char letter = 'a'; letter <= 'z'; ++letter){
        alphabet[letter] = letter - 'a';
    }
    return alphabet;
}

int main(){
    std::unordered_map<char, int> alphabet = generate_english_alphabet();
    return 0;
}