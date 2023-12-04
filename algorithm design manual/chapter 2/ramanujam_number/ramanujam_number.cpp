#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<size_t> generate_ramanujam_numbers(int n){
    std::vector<size_t> ramanujam_numbers;
    for (size_t a = 1; a < n; ++a){
        for (size_t b = a + 1; b < n; ++b){
            size_t c_upper_border = static_cast<size_t>(ceil(pow(pow(a,3) + pow(b,3), 1.0/3.0)));
            for (size_t c = 1; c < c_upper_border; ++c){
                size_t d_upper_border = static_cast<size_t>(ceil(pow(pow(a,3) + pow(b,3) - pow(c, 3), 1.0/3.0)));
                for (size_t d = c + 1; d <d_upper_border; ++d){
                    std::cout << "a =" << a << " ";
                    std::cout << "b =" << b << " ";
                    std::cout << "c =" << c << " ";
                    std::cout << "d =" << d << std::endl;
                    if((pow(a,3) + pow(b,3)) == (pow(c,3) + pow(d,3))){
                        ramanujam_numbers.push_back((pow(a,3) + pow(b,3)));
                    }
                }
            }
        }
    }
    
    return ramanujam_numbers;
}


int main(){
    int n;
    std::cin >> n;
    std::vector<size_t> ramanujam_numbers = generate_ramanujam_numbers(n); 
    std::for_each(ramanujam_numbers.begin(), ramanujam_numbers.end(), [](size_t ramanuj_number)
    {std::cout << ramanuj_number << " ";});
    std::cout << std::endl;
    return 0;
}