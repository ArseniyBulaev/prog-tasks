#include <iostream>

#include "const_op_array.h"

using std::cout, std::endl;

int main(){
    size_t n = 10;
    size_t m = 5;
    ConstOpArray coparray(n, m);
    coparray.insert(2);
    coparray.insert(2);
    coparray.insert(1);
    coparray.insert(10);
    coparray.insert(9);

    cout << coparray.search(9) << endl;
    cout << coparray.search(2) << endl;
    cout << coparray.search(1) << endl;
    return 0;
}