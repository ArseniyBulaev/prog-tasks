#include <iostream>
#include "binary_tree.h"

using std::cout, std::endl;

int main(){
    int array [] = {1, 6, 3, 1, 2, 6};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    Tree root(array, array_size);
    root.traverse([](Node * p) {
        cout <<"I'm node with item " << p->item;
        cout <<". My addres " << p;
        cout << ". My parent addres is " << p->parent << endl;
    });
    return 0;
}
