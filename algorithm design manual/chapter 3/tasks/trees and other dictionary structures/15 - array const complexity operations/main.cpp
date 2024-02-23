#include <iostream>

#include "const_op_array.h"

using std::cout, std::endl;

int main(){
    size_t n = 10;
    size_t m = 5;
    ConstOpArray coparray(n, m);
    cout << coparray.search(21) << endl;
    cout << coparray.search(6) << endl;
    return 0;
}