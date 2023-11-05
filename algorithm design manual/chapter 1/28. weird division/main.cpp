#include <iostream>
#include <vector>

using std::cout, std::endl;

int weird_division(int dividend, int divider){
   int division_result = 0;
   while (dividend >= divider){
    dividend -= divider;
    division_result += 1;
   }
   return division_result;
}

void test(){
    std::vector<std::pair<int, int>> test_cases = {
        {1000, 3},
        {78324, 3124},
        {321, 12}
        };

    for(const std::pair<int, int> & test_case : test_cases){
    cout << (weird_division(test_case.first, test_case.second) == static_cast<int>(test_case.first / test_case.second)) << endl;
    }
    
}

int main(){
    test();
    return 0;
}