#include "Bar.h"
#include "Drink.h"
#include "Cocktail.h"
#include "Beverage.h"
#include "exceptions.h"
#include "Snack.h"
#include "Meniu.h"
#include <string>
#include <vector>
#include <cstdlib>
#include<iomanip>
using namespace std;

Bar::Bar(){
    system("cls");
    numeBar = "Betivii Ramnicul Sarat";
    meseLibere = true;
    nrLocuri = rand() % 50 + 10;
    
    meniu.push_back(new Drink("Bere Ursus", 8.0, 50, 500));
    meniu.push_back(new Drink("Vin Rosu", 15.0, 30, 200));
    meniu.push_back(new Cocktail("Mojito", 25.0, 20, 300, {"rom", "menta", "lime", "soda"}));
    meniu.push_back(new Cocktail("Pina Colada", 28.0, 15, 300, {"rom", "cocos", "ananas"}));
    meniu.push_back(new Beverage("Coca-Cola", 7.0, 100, true, 330));
    meniu.push_back(new Beverage("Apa Plata", 5.0, 100, false, 500));
    meniu.push_back(new Snack("Chips", 6.0, 40, 150, {"sarat"}));
    meniu.push_back(new Snack("Nuci", 8.0, 30, 100, {"sarat", "prajit"}));
}

Bar::Bar(string numeBar, vector<Item*>meniu, vector<Order*>comenzi, bool meseLibere):
numeBar(numeBar), meniu(meniu), comenzi(comenzi), meseLibere(meseLibere){
    if(meseLibere)
        nrLocuri = rand() % 50 + 10;
    else
        nrLocuri = 0;
}
Bar::Bar(const Bar& obj):
numeBar(obj.numeBar),meniu(obj.meniu),comenzi(obj.comenzi),meseLibere(obj.meseLibere){}

Bar& Bar::operator=(const Bar& obj){
    if(this == &obj)
        return *this;
    numeBar=obj.numeBar;
    meniu=obj.meniu;
    comenzi=obj.comenzi;
    meseLibere=obj.meseLibere;
    return *this;
}

Bar::~Bar(){}

ostream& operator<<(ostream& out, const Bar& obj){
    out << "Nume bar: " << obj.numeBar << endl;
    out << "Mese libere: " << (obj.meseLibere ? "Da" : "Nu") << endl;
    out << "Nr locuri: " << obj.nrLocuri << endl;
    out << "Meniu:" << endl;
    for(Item* item : obj.meniu){
        out << item->getDescription() << setprecision(5)<<endl;
    }
    out << "Comenzi active: " << obj.comenzi.size() << endl;
    return out;
}

istream& operator>>(istream& in, Bar& obj){
    cout << "Nume bar: ";
    in >> obj.numeBar;
    cout << "Mese libere? (1=Da / 0=Nu): ";
    in >> obj.meseLibere;
    if(obj.meseLibere)
        obj.nrLocuri = rand() % 50 + 10;
    else
        obj.nrLocuri = 0;
    return in;
}

void Bar::adaugaProdus(Item* item){
    meniu.push_back(item);
}

void Bar::adaugaComanda(Order* order){
    comenzi.push_back(order);
}

void Bar::afisareComenzii(){
    for(int i = 0; i < comenzi.size(); i++){
        cout << "Comanda " << i << ":" << endl;
        cout << *comenzi[i];
    }
}

void Bar::stergeComanda(int id){
    if(id < 0 || id >= comenzi.size())
        throw IDInvalidException();
    delete comenzi[id];
    comenzi.erase(comenzi.begin() + id);
    cout << "Comanda stearsa!" << endl;
}

vector<Item*>& Bar::getMeniu(){
    return meniu;
}