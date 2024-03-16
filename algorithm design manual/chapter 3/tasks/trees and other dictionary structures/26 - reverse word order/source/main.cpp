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


void flip(std::vector<char> & str){
    size_t size = str.size();
    for(size_t i = 0; i < size / 2; ++i){
        std::swap(str[i], str[size - i - 1]);
    }
}

int main(){
    const std::string input_string_path = "..\\input\\sample.txt";
    std::string input = read_text(input_string_path);
    std::vector<char> input_v = transform_string_to_vector(input);
    flip(input_v);
    return 0;
}