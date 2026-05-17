#ifndef ORDER_H
#define ORDER_H

#include "item.h"
#include <string>
#include<vector>
#include<iostream>
using namespace std;

class Order{
protected:
    vector<Item*> listaAchizitii;
    float notaDePlata;
    float tips;
public:

    void CalcNotaPlata();
    void CalcTips();
    void adaugaProdus(Item* item);

    Order();
    Order(vector<Item*>listaAchizitii,float notaDePlata,float tips);
    Order(const Order& obj);
    Order& operator=(const Order& obj);
    ~Order();

    friend ostream& operator<<(ostream& out,const Order&);
    friend istream& operator>>(istream& in,Order&);

};

#endif