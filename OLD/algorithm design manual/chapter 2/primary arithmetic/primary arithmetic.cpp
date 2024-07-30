#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int compute_number_of_carry_operations(size_t number1, size_t number2){
    size_t number_of_carry_operations = 0;
    size_t dig_in_num1 = 0, dig_in_num2 = 0;
    size_t additional_digit = 0;
    while(number1 || number2){
        dig_in_num1 = number1 % 10;
        dig_in_num2 = number2 % 10;
        if (dig_in_num1 + dig_in_num2 + additional_digit > 9){
            ++number_of_carry_operations;
            additional_digit = 1;
        }else{
            additional_digit = 0;
        }
        number1 /= 10;
        number2 /= 10;
    }
    return number_of_carry_operations;
}


std::string make_output(const size_t number_of_carry_operations){
    if(number_of_carry_operations == 0) return "No carry operation.\n";
    if(number_of_carry_operations == 1) return std::to_string(number_of_carry_operations) + " carry operation.\n";
    return std::to_string(number_of_carry_operations) + " carry operations.\n";
}


int main(){
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    std::string line;
    size_t number1, number2;
    size_t number_of_carry_operations;
    while(true){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> number1;
        iss >> number2;
        if(!(number1 || number2)) break;
        number_of_carry_operations = compute_number_of_carry_operations(number1, number2);
        std::cout << line << " ";
        std::cout << make_output(number_of_carry_operations);
    }
    return 0;
}