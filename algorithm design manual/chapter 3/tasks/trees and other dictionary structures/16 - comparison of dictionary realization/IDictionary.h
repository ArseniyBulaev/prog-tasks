#pragma once

#include <string>

class IDictionary{
    virtual ~IDictionary();
    virtual void insert(std::string) = 0;
    virtual bool find(std::string) = 0;
};