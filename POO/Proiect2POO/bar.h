#ifndef BAR_H
#define BAR_H

#include "order.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Bar{
protected:
    string numeBar;
    
    bool meseLibere;
    int nrLocuri;
    vector<Item*> meniu;
    vector<Order*>comenzi;
public:
    Bar();
    Bar(string numeBar,vector<Item*>meniu,vector<Order*>comenzi,bool meseLibere);
    Bar(const Bar& obj);
    Bar& operator=(const Bar& obj);
    ~Bar();

    friend ostream& operator<<(ostream& out,const Bar& obj);
    friend istream& operator>>(istream& in,Bar& obj);

    vector<Item*>& getMeniu();
    void adaugaProdus(Item* item);
    void adaugaComanda(Order* order);
    void afisareComenzii();
    void stergeComanda(int id);

};
#endif