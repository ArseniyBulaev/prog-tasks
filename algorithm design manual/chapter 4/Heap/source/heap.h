#pragma once

#include <vector>
#include <cstddef>

template <typename T>
class Heap{
public:
    Heap(size_t n): n(n), elements(std::vector<T>(n)) {};
private:
    size_t n;
    std::vector<T> elements;
    int get_parent(size_t n);
    size_t young_child(size_t n);
};