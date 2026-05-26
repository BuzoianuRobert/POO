#include "weapon.h"
#include "item.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

Weapon::Weapon(string itemName, string symbol,int statBoost,string description)
: Item(itemName, symbol,statBoost,description){}

void Weapon::use(Player& player) const {
    player.damage += statBoost;
}

string Weapon::getType()const{
    return itemName;
}