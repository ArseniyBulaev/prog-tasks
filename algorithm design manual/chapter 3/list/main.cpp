#include <exception>
#include <iostream>
#include "list.h"

int main(){
    char * strs[] = {"Lincoln", "Jeffreson", "Clinton"};
    List my_list = List(strs, 3);
    my_list.print();
    return 0;
}