#include <iostream>
#include <vector>
#include <bitset>

using std::cout, std::endl;

// O(dividend/divisor)
int weird_division_v1(int dividend, int divisor){

   int sign = ((dividend < 0) ^ 
              (divisor < 0)) ? -1 : 1;

   dividend = abs(dividend);
   divisor = abs(divisor);

   int division_result = 0;
   while (dividend >= divisor){
    dividend -= divisor;
    division_result += 1;
   }
   return sign * division_result;
}

// O(log(dividend))
long long weird_division_v2(long long dividend, long long divisor){
    int sign = ((dividend < 0) ^ 
              (divisor < 0)) ? -1 : 1;

   dividend = abs(dividend);
   divisor = abs(divisor);

   long long division_result = 0;
   long long temp = 0;
   for (int i = 31; i >= 0; --i){
        if(temp + (divisor << i) <= dividend){
            temp += (divisor << i);
            division_result |= (1<<i);
        }
   }
   
   return sign * division_result;
}

void test(){
    std::vector<std::pair<int, int>> test_cases = {
        {1000, 3},
        {78324, 3124},
        {321, 12},
        {-1000, 3},
        {78324, -3124},
        {-321, -12},
        };

    for(const std::pair<int, int> & test_case : test_cases){
    cout << (weird_division_v2(test_case.first, test_case.second) == static_cast<int>(test_case.first / test_case.second)) << endl;
    }
    
}

int main(){
    test();
    return 0;
}