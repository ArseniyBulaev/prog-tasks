#include <algorithm>
#include <random>
#include <numeric>
#include <iostream>
#include <vector>
#include <ostream>

std::ostream & operator << (std::ostream & os, const std::vector<int> & vec){
    for(size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i];
        if(i != vec.size() - 1) std::cout << " ";
    }
    return os;
}

std::vector<int> get_random_vector(size_t size, int min, int max){
    using std::random_device, std::mt19937, std::uniform_int_distribution;
    using std::vector;

    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {min, max};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    vector<int> vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}


int main(){
    using std::cout, std::endl;
    std::vector<int> vec = get_random_vector(10, 1, 10);
    cout << vec << endl;
    return 0;
}