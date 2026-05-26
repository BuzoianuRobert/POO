#include<iostream>
#include<memory>
#include<string>
#include<vector>

#include "weapon.h"
#include "potion.h"
#include "itemfactory.h"
#include "entity.h"
#include "item.h"

using namespace std;


unique_ptr<Item> ItemFactory::create(string type, string name, string symbol, int statBoost, string description){
    if(type=="Weapon")
        return make_unique<Weapon>(name,symbol,statBoost,description);
    else if(type=="Potion")
        return make_unique<Potion>(name,symbol,statBoost,description);
    else 
    throw invalid_argument("Unknown item type: "+ type);
}

