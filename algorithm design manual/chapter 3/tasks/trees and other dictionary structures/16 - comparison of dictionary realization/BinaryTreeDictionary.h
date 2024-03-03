#pragma once

#include "binary_tree.h"
#include "IDictionary.h"


class BinaryTreeDictionary: public IDictionary{
private:
    Tree data;
public:
    void insert(const std::string & value) override;
    bool find (const std::string & value) override;
};