#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstddef>

std::vector<std::string> read_case(){
    std::vector<std::string> lines;
    std::string line, blank;
    std::getline(std::cin, blank); 
    while(std::getline(std::cin, line) && !line.empty()){
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::string> process_case(const std::vector<std::string> & input_case){
    return std::vector<std::string>();
}

int main(){
    std::ifstream input_file("..\\input\\input.txt");
    size_t number_of_cases;
    std::cin.rdbuf(input_file.rdbuf());
    std::ofstream out("..\\output\\output.txt");
    std::cout.rdbuf(out.rdbuf());
    std::cin >> number_of_cases;
    std::string blank;
    std::getline(std::cin, blank); // read rest of first line
    for (size_t i = 0; i < number_of_cases; i++){
       std::vector<std::string> input_case = read_case();
       std::vector<std::string> output_case = process_case(input_case);
    }
    
    
    
    return 0;
}