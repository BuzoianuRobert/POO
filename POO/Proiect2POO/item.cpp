#include "Item.h"
Item::Item():
tipProdus("Nu a fost selectat nici un produs"),nrInStoc(0),pret(0){}

Item::Item(string tipProdus,float pret,int nrInStoc):
tipProdus(tipProdus),pret(pret),nrInStoc(nrInStoc){}

Item::Item(const Item &obj):
tipProdus(obj.tipProdus),pret(obj.pret),nrInStoc(obj.nrInStoc){}

Item& Item::operator=(const Item &obj){
    if(this == &obj)
        return *this;
    tipProdus=obj.tipProdus;
    nrInStoc=obj.nrInStoc;
    pret=obj.pret;
    return *this;
}

Item::~Item(){}

ostream& operator<<(ostream& out,const Item& obj){
    out << "Tipul produsului: "<<obj.tipProdus<<endl;
    out << "In stoc: "<<obj.nrInStoc<<endl;
    out << "Pret un produsului: "<<obj.pret<<endl;
    return out;
}

istream& operator>>(istream& in,Item& obj){
    cout<<"Tip produs:"<<endl;
    in>>obj.tipProdus;
    cout<<"Nr in stoc:"<<endl;
    in>>obj.nrInStoc;
    cout<<"Pretul produsului:"<<endl;
    in>>obj.pret;
    return in;
}
void Item::ClearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

