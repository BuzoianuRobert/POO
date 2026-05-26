#ifndef ITEM_H
#define ITEM_H

#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace std;

class Player;

class Item{
protected:
    string itemName;
    string symbol;
    int statBoost;
    string description;

public:
    Item(string itemName, string symbol, int statBoost, string description);

    virtual void use(Player& player) const = 0;
    virtual string getType() const = 0;
    
    string getItemName() const { return itemName; }  // ✅ inside class
    int getStatBoost() const { return statBoost; }   // ✅ inside class
    
    inline friend ostream& operator<<(ostream& out, const Item& obj){
        out << obj.itemName << " - " << obj.description << endl;
        return out;
    }
    string getSymbol() const { return symbol; }
};

#endif