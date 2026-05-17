#ifndef COCKTAIL_H
#define COCKTAIL_H

#include "item.h"
#include "drink.h"
#include <iostream>
#include <vector>
using namespace std;

class Cocktail : public Drink{
private:
    vector<string> ingrediente;
public:
    Cocktail();
    Cocktail(string tipProdus, float pret, int nrInStoc, float cantitate, vector<string> ingrediente);    
    Cocktail(const Cocktail& obj);
    Cocktail& operator=(const Cocktail& obj);
    ~Cocktail();

    friend ostream& operator<<(ostream& out,const Cocktail&);
    friend istream& operator>>(istream& in,Cocktail&);

     string getDescription() const override;

};
#endif