#pragma once

#include <vector>
#include <cstddef>

template <typename T>
class Heap{
public:
    Heap(): elements(std::vector<T>()) {};
    void insert(T item);
private:
    size_t n = 0;
    std::vector<T> elements;
    int get_parent_indx(size_t n);
    size_t young_child(size_t n);
    void bubble_up(size_t item_indx);
};