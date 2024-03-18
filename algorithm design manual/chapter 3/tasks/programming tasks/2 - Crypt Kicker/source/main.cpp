#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <cstddef>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

std::string read_text(const std::string & file_path){
    std::ifstream input_file(file_path);
    std::string text;
    if(input_file.is_open()){
        input_file.seekg(0, std::ios::end);
        size_t size = input_file.tellg();
        text = std::string(size, ' ');
        input_file.seekg(0);
        input_file.read(&text[0], size); 
    }
    else{
        std::cout << "the file did not open" << std::endl;
    }
    return text;
}

std::unordered_map<char, double> calculate_frequencies(const std::unordered_set<std::string> & words){
    std::unordered_map<char, double> frequencies;
    size_t number_of_letters = 0;
    for(const std::string & word: words){
        for(char letter : word){
            ++frequencies[letter];
            ++number_of_letters; 
        }
    }
    for(auto & letter_frequency: frequencies){
        letter_frequency.second /= number_of_letters;
    }

    return frequencies;
}


std::unordered_map<char, char> get_decryption(const std::unordered_set<std::string> & words, const std::unordered_map<char, double> dictionary_letters_frequencies){
    auto encrypted_letters_frequencies = calculate_frequencies(words);
    return std::unordered_map<char, char>();
}


int main(){
    const std::string input_file_path = "..\\input\\input.txt";
    const std::string input = read_text(input_file_path);
    std::stringstream input_stream(input);
    std::string word, input_line;
    size_t n;
    input_stream >> n;
    std::unordered_set<std::string> dictionary, unique_words_line;
    for(size_t i = 1; i <= n; ++i){
        input_stream >> word;
        dictionary.insert(word);
    }

    auto dictionary_letters_frequencies = calculate_frequencies(dictionary);

    while(getline(input_stream, input_line)){
        if(input_line == "") continue;
        std::stringstream line_stream(input_line);
        std::string word_in_input_line;
        while(line_stream >> word_in_input_line){
            unique_words_line.insert(word_in_input_line);
        }
        get_decryption(unique_words_line, dictionary_letters_frequencies);
    }
    
    return 0;
}