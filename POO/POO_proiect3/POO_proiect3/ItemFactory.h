#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "entity.h"
#include "item.h"
#include<memory>
#include<string>
#include<vector>

class ItemFactory{
public:
    static unique_ptr<Item> create(string type, string name, string symbol, int statBoost, string description);
};

#endif