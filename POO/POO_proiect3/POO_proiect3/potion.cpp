#include "potion.h"
#include "item.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

Potion::Potion(string itemName, string symbol,int statBoost,string description)
: Item(itemName, symbol,statBoost,description){}

void Potion::use(Player& player) const {
    player.health += statBoost;
    if(player.health>100)
        player.health=100;
}

string Potion::getType()const{
    return itemName;
}