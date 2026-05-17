#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "item.h"
#include<string>
#include<iostream>
using namespace std;

class Beverage : public Item{
protected:
    bool carbogazoasa;
    float cantitate;
public:
    string getDescription() const override;

    Beverage();
    Beverage(string tipProdus, float pret, int nrInStoc, bool carbogazoasa, float cantitate);
    Beverage(const Beverage& obj);
    Beverage& operator=(const Beverage& obj);
    ~Beverage();

    friend ostream& operator<<(ostream& out,const Beverage&);
    friend istream& operator>>(istream& in, Beverage&);
};
#endif