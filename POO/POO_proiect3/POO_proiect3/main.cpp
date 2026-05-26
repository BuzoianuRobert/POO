#include<iostream>
#include "game.h"
using namespace std;
int main(){
    try{
        Game::getInstance().run();
    }
    catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
/*
cd "c:\Users\Asus\Desktop\POO\POO_proiect3" && g++ *.cpp -o main && main
*/

