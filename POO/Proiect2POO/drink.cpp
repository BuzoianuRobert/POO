#include "drink.h"
#include "item.h"
#include<iomanip>
Drink::Drink():
Item(),cantitate(0){}

Drink::Drink(string tipProdus, float pret, int nrInStoc,float cantitate):
Item(tipProdus, pret, nrInStoc), cantitate(cantitate){}

Drink::Drink(const Drink& obj):
Item(obj),cantitate(obj.cantitate){}

Drink& Drink::operator=(const Drink& obj){
    if(this == &obj)
        return *this;
    tipProdus=obj.tipProdus;
    nrInStoc=obj.nrInStoc;
    pret=obj.pret;    
    cantitate=obj.cantitate;
    return *this;
}

ostream& operator<<(ostream& out,const Drink& obj){
    out << "Numele produsului: "<<obj.tipProdus<<endl;
    out << "In stoc: "<<obj.nrInStoc<<endl;
    out << "Pret un produsului: "<<obj.pret<<endl;
    out << "Alcoolica: ";
    out<<"Cantitate: "<<obj.cantitate<<setprecision(5)<<endl;
    return out;
}

istream& operator>>(istream& in,Drink& obj){
    cout<<"Numele produs:"<<endl;
    in>>obj.tipProdus;
    cout<<"Nr in stoc:"<<endl;
    in>>obj.nrInStoc;
    cout<<"Pretul produsului:"<<endl;
    in>>obj.pret;
    cout<<"Bautura contine alcool?\n";
    cout<<"(1 = Yes / 0 = No)\n";
    cout<<"Raspuns: "<<endl;
    cout<<"Cantitate: "<<endl;
    in>>obj.cantitate;
    return in;
}
    Drink::~Drink(){}

    string Drink::getDescription() const {
    return "Bautura: " + tipProdus ;
}