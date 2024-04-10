#pragma once

#include <vector>
#include <cstddef>
#include <execution>

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
        bubble_up(elements.size() - 1);
    }
    // O(log(n))
    T extract_min(){
        if(get_size() == 0) throw std::length_error("the heap is empty");
        T min = elements[0];
        elements[0] = elements.back(); // elements[0] = elements[n - 1]
        elements.pop_back();
        bubble_down(0);
        return min;
    }
    size_t get_size(){
        return elements.size();
    }
private:
    std::vector<T> elements;
    int get_parent_indx(size_t n){
        // First element doesn't have a parent
        if(n == 0) return -1;
        else return (static_cast<int>(n / 2));
    }
    size_t get_young_child_index(size_t n){
        return 2 * n + 1; // science indexing start from 0
    }
    void bubble_up(size_t item_indx){
        int parent_indx = get_parent_indx(item_indx);
        if(parent_indx == -1) return; // item is root node
        else if (elements[parent_indx] > elements[item_indx]){
            std::swap(elements[parent_indx], elements[item_indx]);
            bubble_up(parent_indx);
        }
    }
    void bubble_down(size_t item_index){
        size_t min_index = item_index;
        size_t child_index = get_young_child_index(item_index);
        for(size_t i = 0; i <= 1; ++i){
            if(child_index + i < get_size()){
                if(elements[child_index + i] < elements[min_index]){
                    min_index = child_index + i;
                }
            }
        }
        if(min_index != item_index){
            std::swap(elements[item_index], elements[min_index]);
            bubble_down(min_index);
        }
    }
};

template<typename T>
std::vector<T> heap_sort(std::vector<T> elements){
    Heap<T> heap(elements);
    std::vector<T> sorted;
    sorted.reserve(elements.size());
    while(heap.get_size() != 0){
        sorted.push_back(heap.extract_min());
    }
    return sorted;
}