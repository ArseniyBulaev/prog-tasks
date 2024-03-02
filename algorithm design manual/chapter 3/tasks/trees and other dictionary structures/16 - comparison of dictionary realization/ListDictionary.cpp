#include <algorithm>

#include "ListDictionary.h"


void ListDictionary::insert(const std::string & value){
    data.push_back(value);
}

bool ListDictionary::find(const std::string & value){
    return (std::find(data.begin(), data.end(), value) != data.end());
}