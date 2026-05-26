#ifndef INVENTORY_H
#define INVENTORY_H

#include<vector>
#include<string>
#include<iostream>
#include<memory>
#include<stdexcept>
using namespace std;

template<typename T>
class Inventory{
protected:
    vector<unique_ptr<T>> items;
public:
    void addItem(unique_ptr<T> item);
    void removeItem(int index);
    int size();
    void display();
    T* get(int index);

};

template<typename T>
void Inventory<T>::addItem(unique_ptr<T> item){
    items.push_back(move(item));
}
template<typename T>
void Inventory<T>::removeItem(int index){
    if(index < 0 || index >= items.size())
        throw out_of_range("Invalid inventory index");
    items.erase(items.begin() + index);
}

template<typename T>
T* Inventory<T>::get(int index){
    if(index < 0 || index >= (int)items.size())
        throw out_of_range("Invalid inventory index");
    return items[index].get();
}

template<typename T>
int Inventory<T>::size(){
    return items.size();
}

template<typename T>
void Inventory<T>::display(){
    for(auto& x:items){
        cout<<*x;
    }
}

#endif
