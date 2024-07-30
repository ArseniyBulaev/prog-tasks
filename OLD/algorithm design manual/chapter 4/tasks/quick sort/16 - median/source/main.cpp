#include <algorithm>
#include <random>
#include <numeric>
#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>


std::random_device rnd_device;
std::mt19937 mersenne_engine {rnd_device()};

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

int test_median(std::vector<int> v){
    size_t n = v.size() / 2;
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}

typedef std::vector<int>::iterator vec_int_it;

// l_prev - number of elements on the left from previous step
// r_prev - number of elements on the right from previous step
// l_cur - number of elements on the left on current step
// r_cur - number of elements on the right from current step

int median_recursive_step(std::vector<int> & vec, vec_int_it left_border, vec_int_it right_border, int l_prev, int r_prev){
    // Generate pivot
    std::uniform_int_distribution<size_t> dist {0, static_cast<size_t>(std::distance(left_border, right_border) - 1)};
    int pivot = *(left_border + dist(mersenne_engine));
    // Make partition by pivot
    auto pivot_it = std::partition(left_border, right_border, [pivot](const auto& em)
    {
        return em < pivot;
    });
    auto first_of_second_group_it = std::partition(pivot_it, right_border, [pivot](const auto& em)
    {
        return !(pivot < em);
    });
    // Calculate number of elements on the left and on the right from pivot
    int l_cur = std::distance(left_border, first_of_second_group_it - 1);
    int r_cur = std::distance(first_of_second_group_it, right_border);

    int l = l_cur + l_prev;
    int r = r_cur + r_prev;

    if ((l == r) || (l - r == 1)){
        return pivot;
    }
    else{
        if(l > r){
            return median_recursive_step(vec, left_border, first_of_second_group_it - 1, l_prev, r + 1);
        }
        else{
            return median_recursive_step(vec, first_of_second_group_it, right_border, l + 1, r_prev);
        }
    }
}

int median(std::vector<int> vec){
    return median_recursive_step(vec, vec.begin(), vec.end(), 0, 0);
}

void correct_partition(){
     std::vector<int> vec = {2, 4, 10, 1};
    auto first = vec.begin();
    auto last = vec.end();
    int pivot = 2;
    auto middle1 = std::partition(first, last, [pivot](const auto& em)
    {
        return em < pivot;
    });
    auto middle2 = std::partition(middle1, last, [pivot](const auto& em)
    {
        return !(pivot < em);
    });
    std::cout << "middle2 " << *middle2 << std::endl; 
    std::cout << vec << std::endl;
}


int main(){
    using std::cout, std::endl;
    std::vector<int> vec = get_random_vector(10000, 1, 10);
    // vec = {9, 5, 8, 7, 8, 4, 1, 6, 10, 2};
    // cout << vec << endl;
    // std::vector<int> sorted_copy(vec);
    // std::sort(sorted_copy.begin(), sorted_copy.end());
    // cout << sorted_copy << endl;
    cout << "median " << test_median(vec) << endl;
    cout << "median " << median(vec) << endl;
    return 0;
}