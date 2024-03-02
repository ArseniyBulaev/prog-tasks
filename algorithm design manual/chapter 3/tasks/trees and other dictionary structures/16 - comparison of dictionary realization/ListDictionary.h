#include <list>
#include <string>

#include "IDictionary.h"

class ListDictionary: public IDictionary{
private:
    std::list<std::string> data;
public:
    void insert(std::string value) override;
    bool find (std::string value) override;
};