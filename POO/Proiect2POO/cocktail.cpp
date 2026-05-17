#include "cocktail.h"
#include "drink.h"
#include "item.h"
#include<string>
#include<vector>
using namespace std;


Cocktail::Cocktail():Drink(),ingrediente({}){
}
Cocktail::Cocktail(string tipProdus, float pret, int nrInStoc, float cantitate, vector<string> ingrediente) 
: Drink(tipProdus, pret, nrInStoc, cantitate),ingrediente(ingrediente){}

Cocktail::Cocktail(const Cocktail& obj):
    Drink(obj), ingrediente(obj.ingrediente){}

Cocktail& Cocktail::operator=(const Cocktail& obj){
    if(this == &obj)
        return *this;
    tipProdus=obj.tipProdus;
    nrInStoc=obj.nrInStoc;
    pret=obj.pret;    
    cantitate=obj.cantitate;
    ingrediente=obj.ingrediente;
    return *this;   
}

Cocktail::~Cocktail(){}

ostream& operator<<(ostream& out,const Cocktail& obj){
    out << "Tipul produsului: "<<obj.tipProdus<<endl;
    out << "In stoc: "<<obj.nrInStoc<<endl;
    out << "Pret un produsului: "<<obj.pret<<endl;
    out << "Alcoolica: ";
    out<<"Cantitate: "<<obj.cantitate<<endl;
    out<<"Lista ingrediente:"<<endl;
    for(int x=0;x<obj.ingrediente.size();x++){
        out<<obj.ingrediente[x]<<endl;
        
    }
    return out;    
}
    istream& operator>>(istream& in,Cocktail& obj){
    cout<<"Tip produs:"<<endl;
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
    int n;
    cout << "Cate ingrediente are cocktailul? ";
    in >> n;
    for(int i=0; i<n; i++){
        string ing;
        in >> ing;
        obj.ingrediente.push_back(ing);
    }
    return in;
}

string Cocktail::getDescription() const {
    string desc = "Cocktail: " + tipProdus + " - Ingrediente: ";
    for(const string& ing : ingrediente){
        desc += ing + ", ";
    }
    return desc;
}

