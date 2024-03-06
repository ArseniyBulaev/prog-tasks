#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>


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
    const std::string text_path = "text\\input.txt";
    generate_english_alphabet(alphabet, reverse_alphabet);
    std::string original_text = read_text(text_path);
    return 0;
}