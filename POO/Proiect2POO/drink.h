#ifndef DRINK_H
#define DRINK_H

#include "item.h"
#include<string>
#include<iostream>
using namespace std;

class Drink : public Item{
protected:
    float cantitate;
public:
    string getDescription() const override;

    Drink();
    Drink(string tipProdus, float pret, int nrInStoc,float cantitate);
    Drink(const Drink& obj);
    Drink& operator=(const Drink& obj);
    ~Drink();

    friend ostream& operator<<(ostream& out,const Drink&);
    friend istream& operator>>(istream& in, Drink&);
};
#endif