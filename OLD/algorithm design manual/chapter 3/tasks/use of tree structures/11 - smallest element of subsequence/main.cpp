#include <iostream>
#include <vector>

#include "smallest_friendly_array.h"

int main(){
    std::vector<int> input = {4,1,2,5,3};
    SmallestFriendlyArray s_f_array(input);
    for (size_t i = 0; i < input.size(); ++i){
        for (size_t j = i; j < input.size(); ++j){
            std::cout << "smalles of { " << i << " " << j << " } subsequence : ";
            std::cout << s_f_array.get_smallest_between(i, j) << std::endl;
        }
    }
}