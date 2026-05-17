#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
using namespace std;

class Item{
protected:
    string tipProdus;
    int nrInStoc;
    float pret;
public:
    virtual string getDescription() const = 0;    
    Item();
    Item(string tipProdus,float pret,int nrInStoc);
    Item(const Item &obj);
    Item& operator =(const Item &obj);
    virtual ~Item();

    friend ostream& operator<<(ostream& out,const Item&);
    friend istream& operator>>(istream& in, Item&);


    string getTipProdus() const { return tipProdus; }
    float getPret() const { return pret; }
    int getNrInStoc() const { return nrInStoc; }

    void setTipProdus(string t) { tipProdus = t; }
    void setPret(float p) { pret = p; }
    void setNrInStoc(int n) { nrInStoc = n; }
    void ClearScreen();
};
#endif
