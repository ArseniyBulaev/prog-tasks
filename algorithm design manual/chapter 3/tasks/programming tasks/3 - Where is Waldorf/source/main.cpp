#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


void read_case(std::vector<std::vector<char>> & grid, std::vector<std::string> & words, std::ifstream & input_file){
    // Number of columns and lines
    size_t m, n;
    input_file >> m;
    input_file >> n;
    grid.resize(m);
    for (size_t i = 0; i < m; i++){
        grid[i].reserve(n);
    }
    
    // Read grid
    for (size_t i = 0; i < m; ++i){
        for (size_t j = 0; j < n; ++j){
            char letter;
            input_file >> letter;
            grid[i].push_back(letter); 
        }
    }

    // Number of words
    size_t k;
    input_file >> k;
    words.reserve(k);

    // Read words
    for (size_t i = 0; i < k; i++){
        std::string word;
        input_file >> word;
        words.push_back(word);
    }
    
}   


int main(){
    // Input file path
    const std::string input_file_path = "..\\input\\input.txt";
    std::ifstream input_file(input_file_path);
    if(input_file.is_open()){
        // Number of the cases
        size_t number_of_cases;
        input_file >> number_of_cases;
        // Grid
        std::vector<std::vector<char>> grid;
        std::vector<std::string> words;
        for(size_t i = 0; i < number_of_cases; ++i){
            read_case(grid, words, input_file);
        }

        grid.resize(0);
        words.resize(0);
    }
    return 0;
}