#pragma once

#include <vector>

class MinFriendlyArray{
private:
    std::vector<int> elements;
    std::vector<std::vector<int>> min_elements_in_subseq;
    void expand_min_elements_in_subseq(int new_element);
public:
    void insert(int element);

};