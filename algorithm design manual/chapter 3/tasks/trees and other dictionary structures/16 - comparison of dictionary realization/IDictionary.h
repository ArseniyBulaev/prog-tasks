#pragma once

#include <string>

class IDictionary{
public:
    virtual ~IDictionary();
    virtual void insert(std::string) = 0;
    virtual bool find(std::string) = 0;
};