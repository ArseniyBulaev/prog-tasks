#pragma once

#include <vector>
#include <cstddef>

template <typename T>
class Heap{
public:
    Heap(): elements(std::vector<T>()) {};
    // O((el_size)*log(el_size)), el_size - elements size
    Heap(const std::vector<T> & elements){
        for(T element: elements) insert(element);
    }
    // O(log(n))
    void insert(T item){
        elements.push_back(item);
        bubble_up(n);
        ++n;
    }
private:
    size_t n = 0;
    std::vector<T> elements;
    int get_parent_indx(size_t n){
        // First element doesn't have a parent
        if(n == 0) return -1;
        else return (static_cast<int>(n / 2));
    }
    size_t young_child(size_t n){
        return 2 * n;
    }
    void bubble_up(size_t item_indx){
        int parent_indx = get_parent_indx(item_indx);
        if(parent_indx == -1) return; // item is root node
        else if (elements[parent_indx] > elements[item_indx]){
            std::swap(elements[parent_indx], elements[item_indx]);
            bubble_up(parent_indx);
        }
    }
};