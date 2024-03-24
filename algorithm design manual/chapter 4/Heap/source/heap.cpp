#include "heap.h"

template <typename T>
int Heap<T>::get_parent_indx(size_t n){
    // First element doesn't have a parent
    if(n == 0) return -1;
    else return (static_cast<int>(n / 2));
}

template <typename T>
size_t Heap<T>::young_child(size_t n){
    return 2 * n;
}

template <typename T>
void Heap<T>::insert(T item){
    n = n + 1;
    elements.insert(item);
    bubble_up(n);
}

template <typename T>
void Heap<T>::bubble_up(size_t item_indx){
    int parent_indx = get_parent_indx(item_indx);
    if(parent_indx == -1) return; // item is root node
    else if (elements[parent_indx] > elements[item_indx]){
        std::swap(elements[parent_indx], elements[item_indx]);
        bubble_up(get_parent_indx(item_indx));
    }
}