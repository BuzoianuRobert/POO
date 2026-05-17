#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include "item.h"
#include "map.h"
#include "entity.h"

class Player:public Entity{
protected:
    string name;
    int lives;
    vector<unique_ptr<Item>>items;
    int sanity;
public:
    Player (int x,int y,int health,int damage,int speed,char symbol,
    string name,int lives,int sanity);
    void getStats() const override;
    void updateState() override;
    string getType() const override;
    void draw() const override;
    
};
#endif