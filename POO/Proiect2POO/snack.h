#ifndef SNACK_H
#define SNACK_H

#include "item.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Snack:public Item{
protected:
    vector<string> tip;
    float cantitate;
public:
    string getDescription() const override;

    Snack();
    Snack(string tipProdus, float pret, int nrInStoc, float cantitate,vector<string>tip);
    Snack(const Snack& obj);
    Snack& operator=(const Snack& obj);
    ~Snack();

    friend ostream& operator<<(ostream& out,const Snack&);
    friend istream& operator>>(istream& in,Snack&);

};
#endif