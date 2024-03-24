#pragma once

#include <vector>
#include <cstddef>

template <typename T>
class Heap{
public:
    Heap(): elements(std::vector<T>()) {};
private:
    size_t n = 0;
    std::vector<T> elements;
    int get_parent(size_t n);
    size_t young_child(size_t n);
};