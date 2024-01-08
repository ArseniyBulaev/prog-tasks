#pragma once

#include <vector>
#include <cstddef>

class SmallestFriendlyArray{
private:
    std::vector<int> elements;
    std::vector<std::vector<size_t>> smallest_elements_in_subseq;
    void expand_smallest_elements_in_subseq(int new_element);
public:
    SmallestFriendlyArray(const std::vector<int> & vec);
    void insert(int element);
    int get_smallest_between(size_t i, size_t j);
};