#include <unordered_set>
#include "list.h"

bool is_there_a_loop(const List & lst){
    std::unordered_set<Node *> visited;

}


int main(){
    const char * input [] = {"a", "b", "c"};
    size_t size = sizeof(input) / sizeof(input[0]);
    List lst(input, size);
    lst.print();
    Node * a = lst.search("a");
    Node * c = lst.search("c");
    //c->next = a;
    //lst.print();
    return 0;
}