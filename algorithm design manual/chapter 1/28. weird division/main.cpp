#include <iostream>
#include <bitset>

using std::cout, std::endl;

unsigned int weird_abs(int number){
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




int main(){

    return 0;
}