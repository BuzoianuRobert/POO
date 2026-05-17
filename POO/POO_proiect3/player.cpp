#include<iostream>
#include<vector>
#include<string>
#include"player.h"
#include"item.h"
#include"entity.h"
#include"map.h"
using namespace std;

Player::Player(int x, int y, int health, int damage, int speed, char symbol, string name, int lives, int sanity)
:Entity(x, y, health, damage, speed, symbol), name(name), lives(lives), sanity(sanity){}

void Player::getStats()const{
    cout<<"===="<<name<<"'s Stats===="<<endl;
    cout<<"Health:"<<health<<endl;
    cout<<"Damage (with the current weapon):"<<damage<<endl;
    cout<<"Speed(with the current boots):"<<speed<<endl;
    cout<<"Lives remained:"<<lives<<endl;
    cout<<"Sanity level:"<<sanity<<endl;
}
string Player::getType()const{return "Player";}

void Player::updateState(){
    if(health <= 0 || sanity <50){
        lives--;
        health = 100;     
        sanity = 100;
        if(lives == 0)
            cout << "Game over!" << endl;
    }
}
void Player::draw() const{
    cout << symbol;
}