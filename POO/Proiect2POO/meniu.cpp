#include "Meniu.h"
#include "drink.h"
#include "cocktail.h"
#include "beverage.h"
#include "snack.h"
#include "exceptions.h"

Meniu::Meniu(Bar& bar) : bar(bar) {}

void Meniu::bucla(){
    int optiune;
    do {
        system("cls");
        cout << "\n=== BAR MANAGEMENT SYSTEM ===" << endl;
        cout << "1. Afisare meniu bar" << endl;
        cout << "2. Adauga produs in meniu" << endl;
        cout << "3. Adauga comanda" << endl;
        cout << "4. Afisare comenzi" << endl;
        cout << "5. Sterge comanda" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiune: ";
        cin >> optiune;
        switch(optiune){
            case 1: afisareMeniu(); break;
            case 2: adaugaProdus(); break;
            case 3: adaugaComanda(); break;
            case 4: afisareComenzii(); break;
            case 5: stergeComanda(); break;
            case 0: cout << "La revedere!" << endl; break;
            default: cout << "Optiune invalida!" << endl;
        }
    } while(optiune != 0);
}

void Meniu::afisareMeniu(){
    system("cls");
    cout << "\n=== MENIU BAR ===" << endl;
    cout << bar;
    system("pause");
}

void Meniu::adaugaProdus(){
    int tip;
    cout << "\nTip produs:" << endl;
    cout << "1. Drink" << endl;
    cout << "2. Cocktail" << endl;
    cout << "3. Beverage" << endl;
    cout << "4. Snack" << endl;
    cout << "Optiune: ";
    cin >> tip;

    if(tip == 1){
        Drink* d = new Drink();
        cin >> *d;
        bar.adaugaProdus(d);
    } else if(tip == 2){
        Cocktail* c = new Cocktail();
        cin >> *c;
        bar.adaugaProdus(c);
    } else if(tip == 3){
        Beverage* b = new Beverage();
        cin >> *b;
        bar.adaugaProdus(b);
    } else if(tip == 4){
        Snack* s = new Snack();
        cin >> *s;
        bar.adaugaProdus(s);
    } else {
        cout << "Optiune invalida!" << endl;
    }
}

void Meniu::adaugaComanda(){
    system("cls");
    Order* o = new Order();
    cout << "\n=== MENIU ===" << endl;
    vector<Item*>& meniu = bar.getMeniu();
    char continua = 'y';
    for(int i = 0; i < meniu.size(); i++){
        cout << i+1 << ". " << meniu[i]->getDescription() 
            << " - " << meniu[i]->getPret() << " RON" << endl;
        }   
    while(continua == 'y'){
        vector<Item*>& meniu = bar.getMeniu();
        
        int optiune;
        cout << "Alege numarul produsului: ";
        cin >> optiune;
        
        try {
            if(optiune < 1 || optiune > meniu.size())
                throw OptiuneInvalidaException();
            if(meniu[optiune-1]->getNrInStoc() == 0)
                throw StocInsuficientException();
            o->adaugaProdus(meniu[optiune-1]);
            meniu[optiune-1]->setNrInStoc(meniu[optiune-1]->getNrInStoc() - 1);
            cout << "Produs adaugat!" << endl;
        } catch(OptiuneInvalidaException& e){
            cout << e.what() << endl;
        } catch(StocInsuficientException& e){
            cout << e.what() << endl;
        }
        
        cout << "Mai doriti ceva? (y/n): ";
        cin >> continua;
    }
    
    try {
        o->CalcNotaPlata();
        o->CalcTips();
        bar.adaugaComanda(o);
        cout << "\nComanda plasata!" << endl;
        cout << *o;
    } catch(ComandaGoalaException& e){
        cout << e.what() << endl;
        delete o;
    }
    system("pause");
}
void Meniu::afisareComenzii(){
    system("cls");
    bar.afisareComenzii();
    system("pause");
}

void Meniu::stergeComanda(){
    system("cls");
    int id;
    cout << "ID comanda de sters (0, 1, 2...): ";
    cin >> id;
    try {
        bar.stergeComanda(id);
    } catch(IDInvalidException& e){
        cout << e.what() << endl;
    }
    system("pause");
}