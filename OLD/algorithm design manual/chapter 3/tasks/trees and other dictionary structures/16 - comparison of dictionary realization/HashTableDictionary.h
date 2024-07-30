#pragma once

#include <unordered_set>
#include <string>

#include "IDictionary.h"

class HashTableDictionary: public IDictionary {
private:
    std::unordered_set<std::string> data;
public:
    void insert(const std::string & value) override;
};