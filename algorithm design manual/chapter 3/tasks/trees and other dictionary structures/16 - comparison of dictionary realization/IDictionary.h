#pragma once

class IDictionary{
    virtual ~IDictionary();
    virtual void insert() = 0;
    virtual bool find() = 0;
};