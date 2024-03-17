#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <cstddef>
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


std::string get_most_common_pair_of_words(const std::string & str){
    std::unordered_map<std::string, size_t> word_pair_frequency;
    using pair_type = decltype(word_pair_frequency)::value_type;
    std::stringstream str_stream(str);
    std::string first_word;
    std::string second_word;
    str_stream >> first_word;
    while(str_stream >> second_word){
        ++word_pair_frequency[first_word + " " + second_word];
        first_word = second_word;
    }

    auto most_common_pair_of_words = std::max_element
    (
    std::begin(word_pair_frequency), std::end(word_pair_frequency),
    [] (const pair_type & p1, const pair_type & p2) {
        return p1.second < p2.second;
    }
    );
    return most_common_pair_of_words->first;
}


int main(){
    const std::string text_file_path = "..\\input\\text.txt";
    const std::string input_text = read_text(text_file_path);
    std::cout << "most common pair of words: " << get_most_common_pair_of_words(input_text) << std::endl;
    return 0;
}