#include "beverage.h"
#include "item.h"

Beverage::Beverage():
Item(),carbogazoasa(0),cantitate(0){}

Beverage::Beverage(string tipProdus, float pret, int nrInStoc, bool carbogazoasa, float cantitate):
Item(tipProdus, pret, nrInStoc), carbogazoasa(carbogazoasa), cantitate(cantitate){}

Beverage::Beverage(const Beverage& obj):
Item(obj),carbogazoasa(obj.carbogazoasa),cantitate(obj.cantitate){}

Beverage& Beverage::operator=(const Beverage& obj){
    if(this == &obj)
        return *this;
    tipProdus=obj.tipProdus;
    nrInStoc=obj.nrInStoc;
    pret=obj.pret;    
    carbogazoasa=obj.carbogazoasa;
    cantitate=obj.cantitate;
    return *this;
}

ostream& operator<<(ostream& out,const Beverage& obj){
    out << "Tipul produsului: "<<obj.tipProdus<<endl;
    out << "In stoc: "<<obj.nrInStoc<<endl;
    out << "Pret un produsului: "<<obj.pret<<endl;
    out << "Carbogazoasa: ";
    if(obj.carbogazoasa == 1){
        out<<"Yes"<<endl;
    }
    else{
        out<<"No"<<endl;
    }
    out<<"Cantitate: "<<obj.cantitate<<endl;
    return out;
}

istream& operator>>(istream& in,Beverage& obj){
    cout<<"Tip produs:"<<endl;
    in>>obj.tipProdus;
    cout<<"Nr in stoc:"<<endl;
    in>>obj.nrInStoc;
    cout<<"Pretul produsului:"<<endl;
    in>>obj.pret;
    cout<<"Bautura contine acid?\n";
    cout<<"(1 = Yes / 0 = No)\n";
    cout<<"Raspuns: "<<endl;
    in>>obj.carbogazoasa;
    cout<<"Cantitate: "<<endl;
    in>>obj.cantitate;
    return in;
}
    Beverage::~Beverage(){}

    string Beverage::getDescription() const {
    return "Bautura: " + tipProdus + 
           (carbogazoasa ? " (Are acid)" : " (N-are acid)");
}