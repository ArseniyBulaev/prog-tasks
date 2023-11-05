#include <iostream>
#include <bitset>

using std::cout, std::endl;

int sign(int number){
    return number >> 31;
}

unsigned weird_abs(int number){
    int mask = number >> 31;
    return (number + mask) ^ mask;
}

 int get_most_significat_bit(int number){
    if(number == 0) return 0;
    int msb = -1;
    while (number){
        number >>= 1;
        ++msb;
    }
    
    return (1<<msb);
}

int weird_division(int dividend, int divider){
   if (dividend - divider == 0){return 1;}
   if (dividend - divider < 0) {return 0;}
   int dividend_last_bit = dividend & 1;

   int division_result = 0;

   if (dividend_last_bit == 1){
    division_result = weird_division(dividend >> 1, divider) + weird_division((dividend >> 1) + 1, divider);
   }
   else{
    division_result = 2 * weird_division(dividend >> 1, divider);
   }

   if (division_result == 0 && dividend > divider){
        division_result = 1;
   }
    return division_result;
}


int main(){
    int a = 17, b = 3;
    cout << weird_division(a, b) << endl;
    return 0;
}