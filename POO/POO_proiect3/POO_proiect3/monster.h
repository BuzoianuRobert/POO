#ifndef MONSTER_H
#define MONSTER_H

#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include "map.h"
#include "entity.h"
#include "item.h"

using namespace std;

class Monster : public Entity{
protected:
    vector<unique_ptr<Item>> drops;
    bool patrolling=true;
    int XP;
    string name;
    vector<vector<int>> patrolPath;
public:
    Monster(string name,int XP,int x, int y, int health, int damage, int speed, string symbol);
    
    string getType() const;
    void getStats() const;
    void draw() const;
    void updateState(){}
    void updateState(int playerX, int playerY);
};

#endif