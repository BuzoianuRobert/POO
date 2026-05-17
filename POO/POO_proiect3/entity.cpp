#include<iostream>
#include<vector>
#include<string>
#include"entity.h"
#include"map.h"

using namespace std;

Entity::Entity(int x,int y,int health,int damage,int speed,char symbol):
x(x),y(y),health(health),damage(damage),speed(speed),symbol(symbol){}

ostream& operator<<(ostream& out,const Entity& obj){
    out<<"====Entity's informations===="<<endl;
    out<<"Type of mod: ";
    out<<obj.getType();
    out<<endl;
    out<<"Symbol used: ";
    out<<obj.symbol;
    out<<endl;
    out<<"Entity's stats: "<<endl;
    obj.getStats();
    return out;
}