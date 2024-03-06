#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>


void generate_english_alphabet(std::unordered_map<char, int> & alphabet,
std::unordered_map<int, char> & reverse_alphabet){
    for(char letter = 'a'; letter <= 'z'; ++letter){
        int letter_number = letter - 'a';
        alphabet[letter] = letter_number;
        reverse_alphabet[letter_number] = letter;
    }
}


int main(){
    std::unordered_map<char, int> alphabet;
    std::unordered_map<int, char> reverse_alphabet;
    generate_english_alphabet(alphabet, reverse_alphabet);
    return 0;
}