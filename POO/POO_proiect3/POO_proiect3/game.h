#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include "map.h"
#include "entity.h"
#include "player.h"
#include "monster.h"
#include "inventory.h"
#include "itemfactory.h"

class Game {
private:
    struct GroundItem {      
        int x, y;
        unique_ptr<Item> item;
    };

    void init();
    unique_ptr<Map> harta;
    unique_ptr<Player> player;
    vector<unique_ptr<Monster>> mobs;
    vector<GroundItem> groundItems; 
    bool running=true;
    Game() {} 
    Game(const Game&) = delete;           
    Game& operator=(const Game&) = delete; 
public:
    void showMenu();
    void run();
    void update();
    void keyboardInput();
    void render();
    void checkStairs();
    static Game& getInstance(){
        static Game instance; 
        return instance;
    }
    Monster* getMonsterAt(int x, int y);
};
#endif