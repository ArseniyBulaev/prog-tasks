#pragma once

#include <vector>

class MinFriendlyArray{
private:
    std::vector<int> elements;
    std::vector<std::vector<int>> smallest_elements_in_subseq;
    void expand_smallest_elements_in_subseq(int new_element);
    MinFriendlyArray(const std::vector<int> & vec);
public:
    void insert(int element);

};