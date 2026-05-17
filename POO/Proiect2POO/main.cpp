#include "Bar.h"
#include "Meniu.h"
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    Bar bar;
    Meniu menu(bar);
    menu.bucla();
    return 0;
}
/*
cd Desktop\POO\Proiect2POO && C:\msys64\ucrt64\bin\g++.exe main.cpp Item.cpp Drink.cpp Cocktail.cpp Beverage.cpp Snack.cpp Order.cpp Bar.cpp Meniu.cpp -o main.exe && main.exe
*/
