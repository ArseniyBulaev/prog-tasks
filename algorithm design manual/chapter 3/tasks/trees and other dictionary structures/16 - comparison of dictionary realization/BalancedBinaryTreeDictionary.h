#pragma once

#include <set>

#include "IDictionary.h"


class BalancedBinaryTreeDictionary: public IDictionary{
private:
    std::set<std::string> data;
public:
    void insert(const std::string & value) override;
};