#include <iostream>
#include "binary_tree.h"

using std::cout, std::endl;

int main(){
    int array [] = {1, 6, 3, 1, 2, 6};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    Tree root(array, array_size);
    root.traverse([](Tree * node_p) {
        const Tree * parent = node_p->get_parent();
        cout <<"I'm node with item " << node_p->get_item();
        cout <<". My addres " << node_p;
        cout << ". My parent addres is " << parent << endl;
    });
    return 0;
}
