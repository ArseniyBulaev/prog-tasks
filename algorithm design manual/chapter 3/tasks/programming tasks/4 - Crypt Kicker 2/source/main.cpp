#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstddef>

std::vector<std::string> read_case(){
    std::vector<std::string> lines;
    std::string line, blank; 
    while(std::getline(std::cin, line) && !line.empty()){
        lines.push_back(line);
    }
    return lines;
}

bool are_there_gaps_in_the_same_places(const std::string & reference, const std::string & sample){
    for(size_t i = 0; i < reference.size(); ++i){
        if(reference[i] == ' ' && sample[i] != ' ') return false;
    }
    return true;
}

std::vector<std::string> process_case(const std::vector<std::string> & input_case){
    const std::string pangram = "the quick brown fox jumps over the lazy dog";
    std::unordered_map<char, char> permutation;
    std::unordered_map<char, char> reverse_permutation;
    std::vector<std::string> output;
    bool pangram_found = false;
    for(const std::string & line: input_case){
        if(pangram_found) break;
        if((line.size() == pangram.size()) && are_there_gaps_in_the_same_places(pangram, line)){
            // Possible pangram found,
            // but we need to check that no two letters are replaced by the same letter
            pangram_found = true;
            // Make permutation dictionary
            for(size_t i = 0; i < line.size(); ++i){
                // if no two letters are replaced by the same letter
                if((permutation.find(line[i]) == permutation.end())||(reverse_permutation[pangram[i]] == line[i])){
                    permutation[line[i]] = pangram[i];
                    reverse_permutation[pangram[i]] = line[i];
                }
                else{
                    permutation.clear();
                    pangram_found = false;
                    break;
                }
            }
        }
    }

    if(pangram_found){
        for(const std::string & line: input_case){
            std::stringstream encrypted_line_stream;
            for(char symbol: line){
                encrypted_line_stream << permutation[symbol];
            }
            output.push_back(encrypted_line_stream.str());
        }
    }
    else{
        output.push_back("No solution.");
    }

    return output;
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
    std::getline(std::cin, blank); // read first blank line
    for (size_t i = 0; i < number_of_cases; ++i){
       std::vector<std::string> input_case = read_case();
       std::vector<std::string> output_case = process_case(input_case);
       for(size_t j = 0; j < output_case.size(); ++j){
           std::cout << output_case[j] << std::endl;
       }
       if(i != (number_of_cases - 1)) std::cout << '\n';
    }
    return 0;
}