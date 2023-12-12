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

int main(){
    char * strs[] = {"Lincoln", "Jeffreson", "Clinton"};
    List my_list = List(strs,3);
    my_list.print();
    search_test(my_list);
    return 0;
}