#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include "entity.h"
#include "monster.h"
#include "monsterfactory.h"

using namespace std;

unique_ptr<Monster> MonsterFactory::create(string type, int x, int y){
    if(type == "Flamanzean")
        return make_unique<Monster>("Flamanzean", 50, x, y, 50, 10, 4, "F");
    else if(type == "Cersetor")
        return make_unique<Monster>("Cersetor", 25, x, y, 40, 7, 3, "C");
    else
        throw invalid_argument("Unknown monster type: " + type);
}
