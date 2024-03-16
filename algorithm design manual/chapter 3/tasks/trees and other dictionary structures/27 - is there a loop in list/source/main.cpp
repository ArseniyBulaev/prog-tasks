#include <unordered_set>
#include "list.h"

int main(){
    char * input [] = {"a", "b", "c"};
    size_t size = sizeof(input) / sizeof(input[0]);
    List lst(input, size);
    lst.print();
    return 0;
}