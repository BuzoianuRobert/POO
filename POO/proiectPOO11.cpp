#include<iostream>
#include<string.h>
#include<windows.h>
#include <cstdlib> 
#include <ctime>
using namespace std;

class carte{
    char *valoare;
    char *culoare;
    int puncte;

    int calcPuncte();

public:
    friend ostream& operator<<(ostream& out, const carte& obj);
    friend istream& operator>>(istream& in, carte& obj);

    char* getValoare() const { return valoare; }
    char* getCuloare() const { return culoare; }
    int getPuncte()    const { return puncte; }

    carte();
    carte(char *val, char *cul);
    carte(const carte &obj);
    carte& operator=(const carte &obj);
    ~carte();
};

carte::carte(){
    valoare = new char[2];
    strcpy(valoare, "?");
    culoare = new char[2];
    strcpy(culoare, "?");
    puncte = 0;
}

carte::carte(char *val, char *cul){
    valoare = new char[strlen(val)+1];
    strcpy(valoare, val);
    culoare = new char[strlen(cul)+1];
    strcpy(culoare, cul);
    puncte = calcPuncte();
}

carte::carte(const carte &obj){
    valoare = new char[strlen(obj.valoare)+1];
    strcpy(valoare, obj.valoare);
    culoare = new char[strlen(obj.culoare)+1];
    strcpy(culoare, obj.culoare);
    puncte = obj.puncte;

}

carte::~carte(){
    delete[] valoare;
    delete[] culoare;
}

int carte::calcPuncte(){
    if(strcmp(valoare, "2")==0)  return 2;
    if(strcmp(valoare, "3")==0)  return 3;
    if(strcmp(valoare, "4")==0)  return 4;
    if(strcmp(valoare, "5")==0)  return 5;
    if(strcmp(valoare, "6")==0)  return 6;
    if(strcmp(valoare, "7")==0)  return 7;
    if(strcmp(valoare, "8")==0)  return 8;
    if(strcmp(valoare, "9")==0)  return 9;
    if(strcmp(valoare, "10")==0) return 10;
    if(strcmp(valoare, "J")==0)  return 10;
    if(strcmp(valoare, "Q")==0)  return 10;
    if(strcmp(valoare, "K")==0)  return 10;
    if(strcmp(valoare, "A")==0)  return 11;
    return 0;
}

carte& carte::operator=(const carte &obj){
    if(this == &obj) return *this;
    delete[] valoare;
    delete[] culoare;
    valoare = new char[strlen(obj.valoare)+1];
    strcpy(valoare, obj.valoare);
    culoare = new char[strlen(obj.culoare)+1];
    strcpy(culoare, obj.culoare);
    puncte = obj.puncte;
    return *this;
}

ostream& operator<<(ostream &out, const carte &obj){
    out << obj.valoare << " de " << obj.culoare;
    out << " (" << obj.puncte << " puncte)";
    return out;
}

istream& operator>>(istream &in, carte &obj){
    char val[10], cul[10];
    cout << "Valoare carte (2->10, J, Q, K, A): ";
    in >> val;
    cout << "Culoare carte (Inima, Romb, Trefla, InimaN): ";
    in >> cul;
    delete[] obj.valoare;
    delete[] obj.culoare;
    obj.valoare = new char[strlen(val)+1];
    strcpy(obj.valoare, val);
    obj.culoare = new char[strlen(cul)+1];
    strcpy(obj.culoare, cul);
    obj.puncte = obj.calcPuncte();
    return in;
}



class pachet {
private:
    carte* carti;
    int nrcarti;
    int indexCurent;
    static int nrPachete;
    const int NrMaxCarti;

    void creeazaCarti();

public:
    void amesteca();
    carte daCartea();
    bool pachetGol() const;

    pachet();
    pachet(const pachet &obj);
    pachet& operator=(const pachet &obj);
    ~pachet();

    friend ostream& operator<<(ostream& out, const pachet& obj);
    friend istream& operator>>(istream& in, pachet& obj);
};
bool pachet::pachetGol() const{
    if(indexCurent < nrcarti){
        return false;
    }
    else 
        return true;
}
carte pachet::daCartea(){
    if(pachetGol()){
        cout<<"Pachetul este gol!"<<endl;
        return carte();
    }
    return carti[indexCurent++];
}
void pachet::amesteca(){
    srand(time(0));
    
    for(int i = nrcarti-1; i > 0; i--){
        int j = rand() % (i+1); 
        carte temp = carti[i];
        carti[i] = carti[j];
        carti[j] = temp;
    }
    
    indexCurent = 0; 
    cout << "Pachetul a fost amestecat!" << endl;
}



int pachet::nrPachete = 0;

void pachet::creeazaCarti(){
    const char* valori[] = {"2","3","4","5","6","7",
                            "8","9","10","J","Q","K","A"};
    const char* culori[] = {"Inima","Romb","Trefla","InimaN"};
    int index = 0;
    for(int c = 0; c < 4; c++){
        for(int v = 0; v < 13; v++){
            carti[index] = carte((char*)valori[v], (char*)culori[c]);
            index++;
        }
    }
}

pachet::pachet() : NrMaxCarti(52) {
    nrcarti = NrMaxCarti;
    indexCurent = 0;
    nrPachete++;
    carti = new carte[NrMaxCarti];
    creeazaCarti();
}

pachet::pachet(const pachet &obj) : NrMaxCarti(52) {
    nrcarti = obj.nrcarti;
    indexCurent = obj.indexCurent;
    nrPachete++;
    carti = new carte[nrcarti];
    for(int i = 0; i < nrcarti;  i++)
        carti[i] = obj.carti[i];
}

pachet::~pachet() {
    delete[] carti;
    nrPachete--;
}

pachet& pachet::operator=(const pachet &obj) {
    if(this == &obj) return *this;
    delete[] carti;
    nrcarti = obj.nrcarti;
    indexCurent = obj.indexCurent;
    carti = new carte[nrcarti];
    for(int i = 0; i < nrcarti; i++)
        carti[i] = obj.carti[i];
    return *this;
}

ostream& operator<<(ostream &out, const pachet &obj) {
    out << "=== PACHET DE CARTI ===" << endl;
    for(int i = 0; i < obj.nrcarti; i++)
        out << i+1 << ". " << obj.carti[i] << endl;
    return out;
}

istream& operator>>(istream &in, pachet &obj) {
    int raspuns;
    cout << "Vrei sa resetezi pachetul? (1=YES || 0=NO): ";
    in >> raspuns;
    if(raspuns == 1) {
        delete[] obj.carti;
        obj.nrcarti = obj.NrMaxCarti;
        obj.indexCurent = 0;
        obj.carti = new carte[obj.nrcarti];
        obj.creeazaCarti();
        cout << "Pachetul a fost resetat cu succes!" << endl;
    } else {
        cout << "Pachetul nu a fost resetat." << endl;
    }
    return in;
}

class Player{
    char *nume;
    float bani;
    carte *mana;
    int CartiMana;
    bool trage;
    bool peste21;
    bool BlackJack;

public:
   //constructori 
    Player();
    Player(char *nume,float bani);
    Player(const Player &obj);
    ~Player();

    //operatori
    Player &operator=(const Player &obj);
    friend ostream &operator<<(ostream &out,const Player &obj);
    friend istream &operator>>(istream &in,Player &obj);

    //Functii
    void primesteCarte(carte c);
    int calcTotal() const;
    bool Busted()const;
    bool areBlackJack()const; 
};

    Player::Player(){
        nume = new char[10];
        strcpy(nume,"Fara nume");
        bani = 0;
        mana = nullptr;
        CartiMana = 0;
        trage = true;
        peste21 = false;
        BlackJack = false;
    }
    Player::Player(char *nume, float bani){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->bani = bani;
        mana = nullptr;
        CartiMana = 0;
        trage = true;
        peste21 = false;
        BlackJack = false;
    }
    Player::Player(const Player &obj){
        nume = new char[strlen(obj.nume)+1];
        strcpy(nume, obj.nume);
        bani = obj.bani;
        CartiMana = obj.CartiMana;
        trage = obj.trage;
        peste21 = obj.peste21;
        BlackJack = obj.BlackJack;
        if(CartiMana > 0){
            mana = new carte[CartiMana];
           for(int i = 0; i < CartiMana; i++)
                mana[i] = obj.mana[i];
        } 
        else {
          mana = nullptr;
    }
}
    Player::~Player(){
        delete[] nume;
        delete[] mana;
    }
    Player &Player::operator=(const Player &obj){
        if(this == &obj)
            return *this;
        delete[] nume;
        this->nume=new char[strlen(obj.nume)+1];
        strcpy(this->nume,obj.nume);
        this->bani=obj.bani;

        return *this;
    }
    ostream &operator<<(ostream &out, const Player &obj){
    system("cls");
    out << "======================================" << endl;
    out << "Numele jucatorului: " << obj.nume << endl;
    out << "Cati bani are jucatorul: " << obj.bani << " de lei" << endl;
    out<<"\n";
    out << "Carti in mana (" << obj.CartiMana << "):" << endl;
    for(int i = 0; i < obj.CartiMana; i++)
        out << "  " << i+1 << ". " << obj.mana[i] << endl;
    out << "Total: " << obj.calcTotal() << " puncte" << endl;
    out << "Status: ";
    if(obj.peste21)         out << "Eliminat!" << endl;
    else if(obj.BlackJack)  out << "BlackJack!" << endl;
    else                    out << "In joc" << endl;
    out << "======================================" << endl;
    out<<"\n";
    return out;
}
    istream &operator>>(istream &in,Player &obj){
        char nume[50];
        float bani;
        cout<<"Nume jucator:";
        in >> nume;
        cout<<"Cati bani are jucatorul:";
        in >> bani;
        cout<<"\n";
        delete[] obj.nume;
        obj.nume=new char[strlen(nume)+1];
        strcpy(obj.nume,nume);
        obj.bani=bani;
        return in;
    }
void Player::primesteCarte(carte c){
    carte* manaNoua = new carte[CartiMana + 1];
    for(int i = 0; i < CartiMana; i++)
        manaNoua[i] = mana[i];
    manaNoua[CartiMana] = c;
    delete[] mana;
    mana = manaNoua;
    CartiMana++;
    if(calcTotal() > 21)
        peste21 = true;
}
int Player::calcTotal() const{
    int total=0;
    for(int i=0;i<CartiMana;i++)
        total+= mana[i].getPuncte();
    for(int j=0;j<CartiMana;j++){
        if(strcmp(mana[j].getValoare(),"A")==0 && total>21)
        total-=10;
    }
    return total;
}
bool Player::Busted() const{
    if(calcTotal()>21){
        return true;
    }
    else 
        return false;
}
bool Player::areBlackJack() const{
    if(calcTotal()==21 && CartiMana==2)
        return true;
    else   
        return false;
}

class joc {
private:
    int nrJucatori;
    Player* jucatori;
    pachet pachetJoc;
    double potTotal;          
    float mizaMinima;    
    const int MAX_JUCATORI;  

public:
    joc();
    joc(const joc& obj);
    joc& operator=(const joc& obj);
    ~joc();

    friend ostream& operator<<(ostream& out, const joc& obj);
    friend istream& operator>>(istream& in, joc& obj);

    void initializareJoc();
    void rundaJucator(Player& p);
    Player* determinaCastigator();
    void afiseazaStare();
    void ruleazaRunde();
};

joc::joc() : MAX_JUCATORI(4) {
    nrJucatori = 0;
    jucatori = new Player[MAX_JUCATORI];
    pachetJoc.amesteca();
    potTotal = 0;
    mizaMinima = 100;
}
joc::joc(const joc &obj) : MAX_JUCATORI(obj.MAX_JUCATORI) {
    this->jucatori=new Player[obj.MAX_JUCATORI];
    for(int i=0;i<nrJucatori;i++){
        jucatori[i]=obj.jucatori[i];
    }
    this->nrJucatori=obj.nrJucatori;
    this->pachetJoc=obj.pachetJoc;
    this->potTotal=obj.potTotal;
    this->mizaMinima=obj.mizaMinima;
}

joc& joc::operator=(const joc& obj){
    if(this == &obj)
        return *this;
    delete[] jucatori;
    this->nrJucatori = obj.nrJucatori;
    this->pachetJoc = obj.pachetJoc;
    this->potTotal = obj.potTotal;
    this->mizaMinima = obj.mizaMinima;

    this->jucatori = new Player[obj.MAX_JUCATORI];
    for(int i = 0; i < nrJucatori; i++)
        jucatori[i] = obj.jucatori[i];

    return *this;
}
ostream& operator<<(ostream& out, const joc& obj){
    out << "=== STARE JOC ===" << endl;
    out << "Nr jucatori: " << obj.nrJucatori << endl;
    out << "Pot total: " << obj.potTotal << endl;
    out << "Miza minima: " << obj.mizaMinima << endl;
    for(int i = 0; i < obj.nrJucatori; i++)
        out << obj.jucatori[i] << endl;
    return out;
}
istream& operator>>(istream& in, joc& obj){
    cout << "Nr jucatori (max " << obj.MAX_JUCATORI << "): ";
    in >> obj.nrJucatori;
    for(int i = 0; i < obj.nrJucatori; i++){
        cout << "Jucator " << i+1 << ":" << endl;
        in >> obj.jucatori[i];
    }
    return in;
}
joc::~joc(){
    delete[] jucatori;
}

void joc::initializareJoc(){
    cout<<"Nr de jucatori(maxim "<<MAX_JUCATORI<<" jucatori): ";
    cin>>nrJucatori;
    system("cls");
    for(int i=0;i<nrJucatori;i++){
        cin>>jucatori[i];
    }
    pachetJoc.amesteca();

    for(int i=0;i<nrJucatori;i++)
    {
        jucatori[i].primesteCarte(pachetJoc.daCartea());
        jucatori[i].primesteCarte(pachetJoc.daCartea());
    }
    cout<<"Miza minima: ";
    cin>>mizaMinima;
    cout<<"\n";
    cout<<"\n";
}

void joc :: rundaJucator(Player &p){
    cout<<p;
    int alegere;
    int x=0;
    while(x==0){
        cout<<"1=HIT | 0= STAND"<<endl;
        cin>>alegere;
        system("cls");
        if(alegere==1){
            p.primesteCarte(pachetJoc.daCartea());
            cout<<p<<endl;
            if(p.Busted()){
                cout<<"Bust! Ai depasit 21!"<<endl;
                cout<<"\n";
                cout<<"\n";
                cout<<"\n";
                Sleep(3000);
                system("cls");
                x=1;
            }
        }
        else{
            cout<<"Stand!"<<endl;
            x=1;
        }
    }
}

Player *joc::determinaCastigator(){
    Player * castigator=nullptr;
    int maxTotal=0;

    for(int i=0;i<nrJucatori;i++){
        if(!jucatori[i].Busted() && jucatori[i].calcTotal()>maxTotal){
            maxTotal=jucatori[i].calcTotal();
            castigator = &jucatori[i];
        }
    }
    return castigator;
}
void joc::afiseazaStare(){
    cout << "=== STARE JOC ===" << endl;
    cout << "Pot total: " << potTotal << endl;
    cout << "Miza minima: " << mizaMinima << endl;
    cout << "==================" << endl;
    
    for(int i=0;i<nrJucatori;i++){
        cout<<jucatori[i];
    }
}
void joc::ruleazaRunde(){
    for(int i = 0; i < nrJucatori; i++){
        cout << "\n--- Tura jucatorului " << i+1 << " ---" << endl;
        rundaJucator(jucatori[i]);
    }
}

class Meniu {
private:
    joc j;
    int optiune;
    bool activ;

public:
    Meniu();
    Meniu(const Meniu& obj);
    Meniu& operator=(const Meniu& obj);
    ~Meniu();

    friend ostream& operator<<(ostream& out, const Meniu& obj);
    friend istream& operator>>(istream& in, Meniu& obj);

    void afiseazaMeniu();
    void ruleaza();

private:
    void startJocNou();
    void afiseazaStare();
    void afiseazaCastigatorul();
};
Meniu::Meniu(){
    optiune = 0;
    activ = true;
}

Meniu::Meniu(const Meniu& obj){
    optiune = obj.optiune;
    activ = obj.activ;
    j = obj.j;
}

Meniu& Meniu::operator=(const Meniu& obj){
    if(this == &obj) return *this;
    optiune = obj.optiune;
    activ = obj.activ;
    j = obj.j;
    return *this;
}

Meniu::~Meniu(){

}

ostream& operator<<(ostream& out, const Meniu& obj){
    out << "1. Incepe joc nou"           << endl;
    out << "2. Afiseaza starea jocului"  << endl;
    out << "3. Afiseaza castigatorul"    << endl;
    out << "4. Iesire"                   << endl;
    out << "===========================" << endl;
    return out;
}

istream& operator>>(istream& in, Meniu& obj){
    cout << "Alegerea ta: ";
    in >> obj.optiune;
    return in;
}

void Meniu::afiseazaMeniu(){
    cout << *this; 
}

void Meniu::startJocNou(){
    j.initializareJoc();
    j.ruleazaRunde();
}

void Meniu::afiseazaStare(){
    j.afiseazaStare();
}

void Meniu::afiseazaCastigatorul(){
    Player* castigator = j.determinaCastigator();
    if(castigator == nullptr)
        cout << "Toti jucatorii au bust! Nimeni nu castiga!" << endl;
    else
        cout << "Castigatorul este: " << *castigator << endl;
}

void Meniu::ruleaza(){
    while(activ){
        afiseazaMeniu();
        cin >> *this;

        switch(optiune){
            case 1:
                startJocNou();
                break;
            case 2:
                afiseazaStare();
                break;
            case 3:
                afiseazaCastigatorul();
                break;
            case 4:
                cout << "La revedere!" << endl;
                activ = false;
                break;
            default:
                cout << "Optiune invalida! Alege 1-4." << endl;
        }
    }
}
void animatie(){


    for(int j=0;j<4;j++)
    {
        int x=132;
        while(x){
            cout<<"*";
            x--;
            Sleep(10);
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<< "             _______  ___      _______  _______  ___   _      ___  _______  _______  ___   _  __\n"
           "            |  __   ||   |    |   _   ||    ___||   | | |    |   ||   _   ||    ___||   | | ||  |\n"
           "            | |__| _||   |    |  | |  ||   |   ||   |_| |    |   ||  | |  ||   |   ||   |_| ||  |\n"
           "            |     |  |   |    |  |_|  ||   |   ||      _|    |   ||  |_|  ||   |   ||      _||  |\n"
           "            |  __ |_ |   |___ |       ||   |   ||     |_  ___|   ||       ||   |   ||     |_ |__|\n"
           "            | |__|  ||       ||   _   ||   |___ |    _  ||       ||   _   ||   |___ |    _  | __\n"
           "            |_______||_______||__| |__||_______||___| |_||_______||__| |__||_______||___| |_||__|\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    Sleep(500);
    cout << R"(
             ___    __  __       ___     ___    ___     ___    _____      ___   ___   _   _____   _    ___    _  _
            | _ \  |  \/  |     / __|   / _ \  | _ \   / _ \  |_   _|    | __| |   \ | | |_   _| | |  / _ \  | \| |
            |   /  | |\/| |     \__ \  | |_| | |   /  | |_| |   | |      | _|  | |) || |   | |   | | | (_) | | .  |
            |_|_\  |_|  |_|     |___/  |_| |_| |_|_\  |_| |_|   |_|      |___| |___/ |_|   |_|   |_|  \___/  |_|\_|
    )"<<endl;
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    for(int j=0;j<4;j++)
    {
        int x=132;
        while(x){
            cout<<"*";
            x--;
            Sleep(10);
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";

}
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
int main(){
    animatie();
    Meniu m;
    m.ruleaza();
    return 0;
}