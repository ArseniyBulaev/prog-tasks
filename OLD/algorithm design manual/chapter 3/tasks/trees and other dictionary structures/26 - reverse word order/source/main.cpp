#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

std::vector<char> transform_string_to_vector(const std::string & str){
    return std::vector<char>(str.begin(), str.end());
}


void flip(std::vector<char> & str, size_t size, size_t start = 0){
    for(size_t i = 0; i < size / 2; ++i){
        std::swap(str[start + i], str[start + size - (i + 1)]);
    }
}

void reverse_word_order(std::vector<char> & str){
    flip(str, str.size());
    size_t processed_to_here = 0;
    for(size_t i = 0; i <= str.size(); ++i){
        if(str[i] == ' ' || i == (str.size())){
            flip(str, i - processed_to_here, processed_to_here);
            processed_to_here = i + 1;
        }
    }
}


int main(){
    const std::string input_string_path = "..\\input\\sample.txt";
    std::string input = read_text(input_string_path);
    std::vector<char> input_v = transform_string_to_vector(input);
    reverse_word_order(input_v);
    std::cout << std::string(input_v.begin(), input_v.end()) << std::endl;
    return 0;
}