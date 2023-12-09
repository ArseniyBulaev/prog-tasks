#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

std::vector<size_t> find_divisors(size_t n){
    std::vector<size_t> divisors;
    for (size_t i = 1; i <= sqrt(n); ++i){
        if ((n % i) == 0){
            divisors.push_back(i);

            if ((i * i) != n){
                divisors.push_back(n / i);
            }
        }
        
    }
    return divisors;
}

void first_solution(){
    size_t number_of_bulbs;
    while(true){
        std::cin >> number_of_bulbs;
        if(number_of_bulbs == 0) break;
        std::vector<size_t> divisors = find_divisors(number_of_bulbs);
        std::cout << ((divisors.size() % 2) == 0 ? "no" : "yes") << std::endl;
    }
}

void second_solution(){
    size_t number_of_bulbs;
    while(true){
        std::cin >> number_of_bulbs;
        if(number_of_bulbs == 0) break;
        size_t value_of_sqrt = sqrt(number_of_bulbs);
        std::cout << ((value_of_sqrt * value_of_sqrt) == number_of_bulbs ? "yes" : "no") << std::endl;
    }
}


int main(){
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    second_solution();
    return 0;
}