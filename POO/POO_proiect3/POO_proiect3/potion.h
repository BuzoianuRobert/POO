#ifndef POTION_H
#define POTION_H

#include<iostream>
#include<string>
#include<vector>
#include "item.h"
#include "player.h"


class Potion:public Item{
protected:
public:
    Potion(string itemName, string symbol,int statBoost, string description);    
    void use(Player& player) const override;
    string getType()const override;
};
#endif