#ifndef WEAPON_H
#define WEAPON_H

#include<iostream>
#include<string>
#include<vector>
#include "item.h"
#include "player.h"


class Weapon:public Item{
public:
    Weapon(string itemName, string symbol,int statBoost, string description);   
    void use(Player& player) const override;
    string getType()const override;
};
#endif