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





int main(){
    const std::string text_file_path = "..\\input\\input.txt";
    
    return 0;
}