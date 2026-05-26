#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include "item.h"
#include "map.h"
#include "entity.h"
#include "inventory.h"

class Player:public Entity{
protected:
    string name;
    int lives;
    int sanity;
    Inventory<Item> backpack;
public:
    Player (int x,int y,int health,int damage,int speed,string symbol,
    string name,int lives,int sanity);
    void getStats() const override;
    void updateState() override;
    string getType() const override;
    void draw() const override;
    Inventory<Item>& getInventory();

    
    int getLives() const;
    int getSanity() const;
    
    friend class Weapon;
    friend class Potion;
    friend class Armor;
    
};
#endif