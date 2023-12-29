#include "avl_tree.h"
#include <vector>

using std::vector;

int main(){
    vector<int> input = {1,2,3,4,5};
    for(int item : input){
        AVLTree tree(input);
        tree.remove(item);
    }
    
    return 0;
}