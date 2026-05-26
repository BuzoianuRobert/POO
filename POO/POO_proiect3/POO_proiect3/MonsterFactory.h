#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include "monster.h"

using namespace std;

class MonsterFactory{
public:
    static unique_ptr<Monster> create(string type, int x, int y);
};
#endif