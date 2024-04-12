#include <algorithm>
#include <random>
#include <numeric>
#include <iostream>
#include <vector>
#include <ostream>

std::ostream & operator << (std::ostream & os, const std::vector<int> & v){
    for(size_t i = 0; i < v.size(); i++){
        std::cout << v[i];
        if(i != v.size() - 1) std::cout << " ";
    }
    return os;
}


int main(){
    using std::cout, std::endl;
    std::vector<int> v = { 1, 2, 3};
    cout << v << endl;
    return 0;
}