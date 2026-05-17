#ifndef ENTITY_H
#define ENTITY_H
#include<iostream>
#include"map.h"


class Entity{
protected:
    int x;
    int y;
    int health;
    int damage;
    int speed;
    char symbol;
public:
    Entity(int x,int y,int health,int damage,int speed,char symbol);
    
    virtual void getStats() const=0;
    virtual void updateState() =0;
    virtual string getType() const =0;
    virtual void draw() const =0;
    
    friend std::ostream& operator<<(std::ostream& out,const Entity& obj);

};
#endif