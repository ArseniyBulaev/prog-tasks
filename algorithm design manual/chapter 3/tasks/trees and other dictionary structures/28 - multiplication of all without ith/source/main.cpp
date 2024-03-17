#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

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
    const std::string numbers_file_path = "..\\input\\numbers.txt";
    const std::string numbers_as_str = read_text(numbers_file_path);
    std::stringstream numbers_as_str_stream(numbers_as_str);
    std::vector<int> X(std::istream_iterator<int>(numbers_as_str_stream),{});
	return 0;
}