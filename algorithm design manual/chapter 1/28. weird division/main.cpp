#include <iostream>
#include <bitset>

using std::cout, std::endl;

unsigned int weird_abs(int number){
    int mask = number >> 31;
    return (number + mask) ^ mask;
}

 


int main(){

    return 0;
}