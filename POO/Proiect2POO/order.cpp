#include "item.h"
#include "order.h"
#include "drink.h"
#include "snack.h"
#include "exceptions.h"
#include "beverage.h"
#include "cocktail.h"
#include <iomanip>
Order::Order():
listaAchizitii({}),notaDePlata(0),tips(0){}

Order::Order(vector<Item*>listaAchizitii,float notaDePlata,float tips):
listaAchizitii(listaAchizitii),notaDePlata(notaDePlata),tips(tips){}

Order::Order(const Order& obj):
listaAchizitii(obj.listaAchizitii),notaDePlata(obj.notaDePlata),tips(obj.tips){}

Order::~Order(){}

Order& Order::operator=(const Order& obj){
    if(this == &obj)
        return *this;
    listaAchizitii=obj.listaAchizitii;
    notaDePlata=obj.notaDePlata;
    tips=obj.tips;
    return *this;

}

ostream& operator<<(ostream& out,const Order& obj){
    out<<"Lista de achizitii:"<<endl;
    for(Item* x : obj.listaAchizitii){
        out << x->getDescription() << setprecision(5)<<endl;
    }
    out<<"Nota de plata: "<<obj.notaDePlata<<endl;
    out<<"Tips: "<<obj.tips<<endl;
    return out;
}

void Order::CalcNotaPlata(){
    if(listaAchizitii.empty())
        throw ComandaGoalaException();
    notaDePlata = 0;
    for(Item* item : listaAchizitii){
        notaDePlata += item->getPret();
    }
}
void Order::CalcTips(){
    tips = notaDePlata * 0.10;
}

istream& operator>>(istream& in, Order& obj){
    int n;
    cout << "Cate produse contine comanda? ";
    in >> n;
    for(int i = 0; i < n; i++){
        int tip;
        cout << "Tip produs (1=Drink, 2=Cocktail, 3=Beverage, 4=Snack): ";
        in >> tip;
        if(tip == 1){
            Drink* d = new Drink();
            in >> *d;
            obj.listaAchizitii.push_back(d);
        } else if(tip == 2){
            Cocktail* c = new Cocktail();
            in >> *c;
            obj.listaAchizitii.push_back(c);
        } else if(tip == 3){
            Beverage* b = new Beverage();
            in >> *b;
            obj.listaAchizitii.push_back(b);
        } else if(tip == 4){
            Snack* s = new Snack();
            in >> *s;
            obj.listaAchizitii.push_back(s);
        }
    }
    return in;
}

void Order::adaugaProdus(Item* item){
    listaAchizitii.push_back(item);
}
