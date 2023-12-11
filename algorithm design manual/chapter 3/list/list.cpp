#include <iostream>

#include "list.h"

 List::~List(){
    Node * current = head;
    while(current){
        Node * buf = current;
        std::cout << "delete node: " << buf->data << std::endl;
        current = current->next;
        delete buf;
    }
}

List::List(char ** strs, int size){
    head = new Node {strs[0], nullptr};
    Node * current = head;
    for(int i = 1; i < size; ++i){
        current->next = new Node {strs[i], nullptr};
        current = current->next;
    }
}


void List::print(){  
    const Node * current = head;
    while (current != nullptr){
        std::cout << current->data;
        if(current->next != nullptr) std::cout << "->";
        current = current->next;
    }
    std::cout << std::endl;
}
