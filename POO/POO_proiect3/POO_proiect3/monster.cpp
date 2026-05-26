#include<iostream>
#include<vector>
#include<string>
#include<memory>

#include "monster.h"
#include "entity.h"
#include "item.h"

using namespace std;

Monster::Monster(string name,int XP,int x, int y, int health, int damage, int speed, string symbol):
Entity( x,  y,  health,  damage,  speed,  symbol),XP(XP),name(name){}

void Monster::draw() const{
    cout << symbol;
}

string Monster::getType()const{
    return name;
}

void Monster::getStats() const {}

void Monster::updateState(int playerX, int playerY){
    if(health <= 0) return;
    
    int dx = playerX - x;
    int dy = playerY - y;
    int distance = abs(dx) + abs(dy);
    
    if(distance <= 5 && distance > 1){
        if(abs(dx) > abs(dy))
            x += (dx > 0) ? 1 : -1;
        else
            y += (dy > 0) ? 1 : -1;
    }
    else if(distance == 1){ 

    }
}
