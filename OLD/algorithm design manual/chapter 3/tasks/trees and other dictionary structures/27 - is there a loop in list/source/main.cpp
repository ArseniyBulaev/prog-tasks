#include <iostream>
#include <unordered_set>
#include "list.h"




int main(){
    const char * input [] = {"a", "b", "c"};
    size_t size = sizeof(input) / sizeof(input[0]);
    List lst(input, size);
    lst.print();
    std::cout << "is there a loop ? " << lst.is_there_a_loop() << std::endl;
    Node * a = lst.search("a");
    Node * c = lst.search("c");
    c->next = a;
    std::cout << "is there a loop ? " << lst.is_there_a_loop() << std::endl;
    c->next = nullptr;
    return 0;
}