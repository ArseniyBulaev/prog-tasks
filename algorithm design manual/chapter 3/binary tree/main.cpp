#include <iostream>
#include "binary_tree.h"

using std::cout, std::endl;

void traverse_test(Tree & tree){
    tree.traverse([](Node * p) {
        cout <<"I'm node with item " << p->item;
        cout <<". My addres " << p;
        cout << ". My parent addres is " << p->parent << endl;
    });
}

void search_test(Tree & tree, int * items_to_search, size_t items_to_search_size){
    cout << "SEARCH:" << endl;
    Node * search_result = nullptr;
    for(size_t i = 0; i < items_to_search_size; ++i){
        int item_to_search = items_to_search[i];
        search_result = tree.search(item_to_search);
        if(search_result != nullptr){
           cout << "found node with item: " << search_result->item << endl; 
        }
    }
    cout << "search for non-exist node..." << endl;
    int item_to_search = -1;
    search_result = tree.search(item_to_search);
    if(search_result != nullptr){
        cout << "found node with item: " << search_result->item << endl; 
    }
    else{
        cout << "search result is empty" << endl;
    }
}

void maximum_test(const Tree & tree){
    cout << "MAXIMUM:" << endl;
    Node * max = tree.maximum();
    cout << "value of max element of the tree: " << max->item << endl;
}

void minimum_test(const Tree & tree){
    cout << "MINIMUM:" << endl;
    Node * min = tree.minimum();
    cout << "value of min element of the tree: " << min->item << endl;
} 

void test(){
    int array [] = {1, 6, 3, 1, 2, 6};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    Tree root(array, array_size);
    // search_test(root, array, array_size);
    minimum_test(root);
    maximum_test(root);
}

int main(){
    test();
    return 0;
}
