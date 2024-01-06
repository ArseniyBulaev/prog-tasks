#pragma once

#include <vector>

class SmallestFriendlyArray{
private:
    std::vector<int> elements;
    std::vector<std::vector<int>> smallest_elements_in_subseq;
    void expand_smallest_elements_in_subseq(int new_element);
    SmallestFriendlyArray(const std::vector<int> & vec);
public:
    void insert(int element);
    int get_smallest_between(size_t i, size_t j);
};