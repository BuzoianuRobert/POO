#ifndef MENIU_H
#define MENIU_H

#include "bar.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Meniu {
private:
    Bar& bar;  
public:
    Meniu(Bar& bar);
    void afisareMeniu();
    void adaugaProdus();
    void adaugaComanda();
    void afisareComenzii();
    void stergeComanda();
    void bucla(); 
};

#endif