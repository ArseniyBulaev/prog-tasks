#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout, std::endl;
using std::unordered_map;

using ramanujam_unordered_map = unordered_map<size_t, std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>>>;

ramanujam_unordered_map generate_ramanujam_numbers(int n){
    ramanujam_unordered_map ramanujam_numbers;
    unordered_map<size_t, std::pair<size_t, size_t>> cache;
    for (size_t a = 1; a < n; ++a){
        for (size_t b = 1; b < a; ++b){
            size_t n = a*a*a + b*b*b;
            if (cache.find(n) != cache.end()){
                ramanujam_numbers[n] = {cache[n], {a, b}};
            }
            else{
                cache[n] = {a, b};
            }
        }
    }
    return ramanujam_numbers;
} 



int main(){
    int n;
    std::cin >> n;
    ramanujam_unordered_map ramanujam_numbers = generate_ramanujam_numbers(n);
    std::vector<size_t> keys;
    keys.reserve (ramanujam_numbers.size());
    for (auto& it : ramanujam_numbers) {
        keys.push_back(it.first);
    }
    std::sort (keys.begin(), keys.end());
    for (auto& ramanujam_number : keys) {
        const auto & ramanujam_pair = ramanujam_numbers[ramanujam_number];
        const auto & a_and_b = ramanujam_pair.first;
        const auto & c_and_d = ramanujam_pair.second;
        cout << "ramanujam number: " << ramanujam_number << endl;
        cout << "a = "  << a_and_b.first << ", b = " << a_and_b.second << endl;
        cout << "c = "  << c_and_d.first << ", d = " << c_and_d.second << endl;
        cout << endl;
    }
    return 0;
}