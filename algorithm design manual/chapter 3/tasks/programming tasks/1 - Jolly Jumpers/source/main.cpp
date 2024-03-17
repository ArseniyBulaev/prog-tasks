#include <string>
#include <fstream>
#include <vector>
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


bool is_it_jolly(const std::vector<int> & sample){
    const int n = sample[0];
    // The definition implies that any sequence of a single integer is a jolly jumper
    if(n == 1) return true;
    std::vector<bool> jolly_condition(n - 1, false);
    for(size_t i = 1; i < n; ++i){
        size_t possible_part_of_jolly_condition = abs(sample[i] - sample[i + 1]);
        if(possible_part_of_jolly_condition <= n){
            jolly_condition[possible_part_of_jolly_condition - 1] = true;
        }
    }
    return std::all_of(jolly_condition.begin(), jolly_condition.end(), [](bool v) { return v; });
}


int main(){
    const std::string input_file_path = "..\\input\\input.txt";
    const std::string input = read_text(input_file_path);
    std::stringstream input_stream(input);
    std::string line;
    while(getline(input_stream, line)){
        std::stringstream line_stream(line);
        std::cout << (is_it_jolly(std::vector<int>(std::istream_iterator<int>(line_stream),{})) ? "Jolly" : "Not jolly") << std::endl;
    }
    
    return 0;
}