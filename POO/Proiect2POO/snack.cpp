#include "item.h"
#include "snack.h"
#include<iomanip>

Snack::Snack():
Item(),tip({}){}

Snack::Snack(string tipProdus, float pret, int nrInStoc, float cantitate,vector<string>tip):
Item(tipProdus,pret,nrInStoc),cantitate(cantitate),tip(tip){}

Snack::Snack(const Snack& obj):
Item(obj),cantitate(obj.cantitate),tip(obj.tip){}

Snack::~Snack(){}

Snack& Snack::operator=(const Snack& obj){
    if(this == &obj)
        return *this;
    tipProdus=obj.tipProdus;
    nrInStoc=obj.nrInStoc;
    pret=obj.pret;    
    tip=obj.tip;
    cantitate=obj.cantitate;
    return *this;
}

ostream& operator<<(ostream& out,const Snack& obj){
    out << "Tipul produsului: "<<obj.tipProdus<<endl;
    out << "In stoc: "<<obj.nrInStoc<<endl;
    out << "Pret un produsului: "<<obj.pret<<endl;
    out<<"Cantitate: "<<obj.cantitate<<setprecision(5)<<endl;
    out<<"Tipul snack-ului: ";
    for(const string& t:obj.tip){
        out<<t<<" ";
    }
    out<<endl;
    return out;
}
istream& operator>>(istream& in,Snack& obj){
    cout<<"Tip produs:"<<endl;
    in>>obj.tipProdus;
    cout<<"Nr in stoc:"<<endl;
    in>>obj.nrInStoc;
    cout<<"Pretul produsului:"<<endl;
    in>>obj.pret;
    int n;
    cout << "Cate tipuri are snack-ul? ";
    in >> n;
    for(int i = 0; i < n; i++){
        string t;
        cout << "Tip " << i+1 << ": ";
        in >> t;
        obj.tip.push_back(t);
    }
    cout<<"Cantitate: "<<endl;
    in>>obj.cantitate;
    return in;
}

string Snack::getDescription() const {
    return "Snack: " + tipProdus + " - Cantitate: " + to_string(cantitate) + "g";
}