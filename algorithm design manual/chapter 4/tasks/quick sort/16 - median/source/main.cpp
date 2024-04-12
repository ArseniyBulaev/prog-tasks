#include <algorithm>
#include <random>
#include <numeric>
#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>

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

void partition_test(std::vector<int> vec){
    using std::random_device, std::mt19937, std::uniform_int_distribution;
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<size_t> dist {0, vec.size() - 1};
    int pivot = vec[dist(mersenne_engine)];
    auto it = std::partition(vec.begin(), vec.end(), [pivot](int e) { return e < pivot;});
    
    std::cout << "pivot = " << pivot << std::endl;
    std::cout << "original vector" << std::endl;
    std::cout << vec << std::endl;
    std::cout << "vector after partiton" << std::endl;
    std::copy(std::begin(vec), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "* ";
    std::copy(it, std::end(vec), std::ostream_iterator<int>(std::cout, " "));
}

int test_median(std::vector<int> &v){
    size_t n = v.size() / 2;
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}


/*
int median(vector){
    return median_recursive_step(vector, 0, vector.size() - 1, 0, 0);
}

int median_recursive_step(vector, left_border, right_border, num_of_el_on_the_left, num_of_el_on_the_right){
    1. Generate pivot
    3. Make partition by pivot
    2. Calculate number of elements on the left and on the right from pivot
    if (num_of_el_on_the_left_from_pivot == num_of_el_on_the_right_from_pivot || 
        num_of_el_on_the_left_from_pivot - num_of_el_on_the_right_from_pivot == 1){
        return pivot;
    }
    else{
        if(num_of_el_on_the_left_from_pivot > num_of_el_on_the_right_from_pivot){
            num_of_el_on_the_right += num_of_el_on_the_right_from_pivot;
            return median_recursive_step(vector, left_border, pivot - 1, num_of_el_on_the_left, num_of_el_on_the_right);
        }
        else{
            num_of_el_on_the_left += num_of_el_on_the_left_from_pivot;
            return median_recursive_step(vector, pivot, right_border, num_of_el_on_the_left, num_of_el_on_the_right);
        }
    }
}
*/

int main(){
    using std::cout, std::endl;
    std::vector<int> vec = get_random_vector(4, 1, 10);
    std::cout << vec << std::endl;
    std::cout << "median " << test_median(vec) << std::endl;
    return 0;
}