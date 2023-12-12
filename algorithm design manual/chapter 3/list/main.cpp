#include <exception>
#include <iostream>
#include "list.h"

void search_test(const List & source){
     char * strs[] = {"Lincoln", "Jeffreson", "Washington",  "Clinton1", "Obama", "Trump"};
     char * target;
     Node * search_result;
     for(size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i){
        target = strs[i];
        search_result = source.search(target);
        if (search_result != nullptr){
           std::cout << "found: " << search_result->data << std::endl;  
        }
        else{
           std::cout << "node: " << target << " not found" << std::endl;
        }
     }
    
}

void insert_test(List & source){
    char * some_string = "Bulka";
    source.insert("Bulka");
    if(source.search(some_string)){
        std::cout << some_string << " inserted into source" << std::endl;
    }
    else{
        std::cout << "something wrong happend T_T" << std::endl;
    }
}

void predecessor_test(List & source, char ** strs, size_t strs_size){
    Node * predecessor;
    char * element;
    for(size_t i; i < strs_size; ++i){
        element = strs[i];
        predecessor = source.predecessor(element);
        if(predecessor != nullptr){
            std::cout << "predecessor of " << strs[i] << " is " << predecessor->data << std::endl; 
        }
        else{
            std::cout << "predecessor of " << strs[i] << " not found" << std::endl;
        }
    }
    predecessor = source.predecessor("Bulka");
    if(predecessor != nullptr){
        std::cout << "somehow predecessor of a non-existent element is " << predecessor->data << std::endl;
    }
    else{
        std::cout << "predecessor of a non-existent element doesn't exist" << std::endl;
    }
}

void erase_test(const List & source,char ** strs, size_t strs_size){
    char * element;
    for(size_t i = 0; i < strs_size; ++i){
        List copy = source;
        element = strs[i];
        copy.print();
        copy.erase(element);
        copy.print();
    }
}

int main(){
    char * strs[] = {"Lincoln", "Jeffreson", "Clinton"};
    size_t size = sizeof(strs)/sizeof(strs[0]);
    List my_list = List(strs,3);
    // my_list.print();
    // search_test(my_list);
    // insert_test(my_list);
    // predecessor_test(my_list, strs, size);
    erase_test(my_list, strs, size);
    return 0;
}