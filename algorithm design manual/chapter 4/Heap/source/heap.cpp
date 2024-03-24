#include "heap.h"

template <typename T>
int Heap<T>::get_parent(size_t n){
    // First element doesn't have a parent
    if(n == 0) return -1;
    else return (static_cast<int>(n / 2));
}

template <typename T>
size_t Heap<T>::young_child(size_t n){
    return 2 * n;
}