#include "BinaryTreeDictionary.h"


void BinaryTreeDictionary::insert(const std::string & value){
    if(!find(value)){
        data.insert(value);
    }
}

bool BinaryTreeDictionary::find(const std::string & value){
    return data.search(value);
}