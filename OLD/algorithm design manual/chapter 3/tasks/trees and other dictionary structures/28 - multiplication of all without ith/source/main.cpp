#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <cstddef>

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

std::vector<int> multiplication_of_all_without_ith(const std::vector<int> & numbers){
    size_t n = numbers.size();
    std::vector<int> multiplying_elements_on_the_left(n, 1);
    std::vector<int> multiplying_elements_on_the_right(n, 1);
    std::vector<int> all_multiplications(n, 1);

    // make multiplying elements on the left
    for(size_t i = 1; i < n; ++i){
        multiplying_elements_on_the_left[i] = multiplying_elements_on_the_left[i - 1] * numbers[i - 1];
    }

    // make multiplying elements on the right
    for(int i = n - 2; i >= 0; --i){
        multiplying_elements_on_the_right[i] = multiplying_elements_on_the_right[i + 1] * numbers[i + 1];
    }

    // make all multiplications
    for(size_t i = 0; i < n; ++i){
        all_multiplications[i] = multiplying_elements_on_the_left[i] * multiplying_elements_on_the_right[i];
    }

    return all_multiplications;
}

int main(){
    const std::string numbers_file_path = "..\\input\\numbers.txt";
    const std::string numbers_as_str = read_text(numbers_file_path);
    std::stringstream numbers_as_str_stream(numbers_as_str);
    std::vector<int> X(std::istream_iterator<int>(numbers_as_str_stream),{});
    std::vector<int> all_multiplications = multiplication_of_all_without_ith(X);
    for(size_t i = 0; i < X.size(); i++){
        std::cout << "multiplication of all elements without " << X[i] << " equals " << all_multiplications[i] << std::endl;
    }
    return 0;
}