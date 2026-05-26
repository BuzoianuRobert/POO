#ifndef ENTITY_H
#define ENTITY_H
#include<iostream>
#include"map.h"
#include<string>
using namespace std;

class Entity{
protected:
    int x;
    int y;
    int health;
    int damage;
    int speed;
    string symbol;
public:
    Entity(int x,int y,int health,int damage,int speed,string symbol);
    
    virtual void getStats() const;
    virtual void updateState() = 0;
    virtual void updateState(int px, int py){} 
    virtual string getType() const =0;
    virtual void draw() const =0;

int getX() const { return x; }
int getY() const { return y; }
string getSymbol() const { return symbol; }
int getHealth() const { return health; }
int getDamage() const { return damage; }
int getSpeed() const { return speed; }

void setX(int x) { this->x = x; }
void setY(int y) { this->y = y; }
void setHealth(int health) { this->health = health; }
    
    friend std::ostream& operator<<(std::ostream& out,const Entity& obj);

};
#endif