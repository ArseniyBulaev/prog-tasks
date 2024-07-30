#include <string>

#include "list.h"

int main(){
    List lst;
    lst.insert("a");
    lst.insert("b");
    lst.insert("c");
    lst.print();
    lst.reverse();
    return 0;
}