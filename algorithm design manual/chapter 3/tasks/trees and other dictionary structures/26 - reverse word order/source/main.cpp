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
    for(size_t i = start; i < size / 2; ++i){
        std::swap(str[i + start], str[size - i - 1]);
    }
}

void reverse_word_order(std::vector<char> & str){

}


int main(){
    const std::string input_string_path = "..\\input\\sample.txt";
    std::string input = read_text(input_string_path);
    std::vector<char> input_v = transform_string_to_vector(input);
    flip(input_v, input_v.size());
    return 0;
}