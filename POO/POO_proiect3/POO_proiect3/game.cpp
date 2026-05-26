#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include "game.h"
#include "player.h"
#include "entity.h"
#include "monsterfactory.h"
#include <conio.h>
#include <algorithm>
#include "itemfactory.h"
using namespace std;



void Game::run(){
    init();
    showMenu();
    while(running){
        keyboardInput();
        update();
        if(!running) break;
        render();
    }
    if(!running){
        system("cls");
        cout << "You escaped the dungeon! You WIN!" << endl;
        cout << "Press any key to exit..." << endl;
        _getch();
    }
}

void Game::init(){
    harta = make_unique<Map>("mapa.txt");
    player = make_unique<Player>(3, 2, 100, 10, 2, "$", "Hero", 3, 100);
    mobs.push_back(MonsterFactory::create("Flamanzean", 26, 6));
    mobs.push_back(MonsterFactory::create("Flamanzean", 20, 7));
    mobs.push_back(MonsterFactory::create("Flamanzean", 30,11));
    mobs.push_back(MonsterFactory::create("Flamanzean", 29, 13));

    mobs.push_back(MonsterFactory::create("Cersetor", 20, 10));
    mobs.push_back(MonsterFactory::create("Flamanzean", 9, 12));
    groundItems.push_back({5, 2, ItemFactory::create("Weapon", "Briceag", "X", 15, "A sharp sword")});
    groundItems.push_back({7, 2, ItemFactory::create("Potion", "Ciucas", "B", 15, "A tasty beer")});
    groundItems.push_back({15,8 , ItemFactory::create("Potion", "Ciucas", "B", 15, "A tasty beer")});
    groundItems.push_back({16, 11, ItemFactory::create("Potion", "Ciucas", "B", 15, "A tasty beer")});
    groundItems.push_back({9, 12, ItemFactory::create("Potion", "Ciucas", "B", 15, "A tasty beer")});
    groundItems.push_back({10, 3, ItemFactory::create("Potion", "Ciucas", "B", 15, "A tasty beer")});

}
void Game::showMenu(){
    cout<<"============================="<<endl;
    cout<<"1. Start Game"<<endl;
    cout<<"2. Show Player Stats"<<endl;
    cout<<"3. Show Inventory"<<endl;
    cout<<"4. Use Item"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"=============================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int choise;
    cout<<"Your choise: ";
    do{
        cin>>choise;
        switch(choise){
            case 1: running = true; return;
            case 2:player->getStats();break;
            case 3:player->getInventory().display();break;
            case 4:
            case 5:running = false;break;
        }
    }while(choise !=5);
}

void Game::keyboardInput(){
    char key=_getch();
    switch(key){
case 'w':{
    int newX = player->getX();
    int newY = player->getY() - 1;
    Monster* mob = getMonsterAt(newX, newY);
    if(mob){
        mob->setHealth(mob->getHealth() - player->getDamage());
        cout << "Hit! Monster health: " << mob->getHealth() << endl;
    }
    else if(harta->isWalkable(newX, newY))
        player->setY(newY);
    break;
}
case 'a':{
    int newX = player->getX()-1;
    int newY = player->getY();
    Monster* mob = getMonsterAt(newX, newY);
    if(mob){
        mob->setHealth(mob->getHealth() - player->getDamage());
        cout << "Hit! Monster health: " << mob->getHealth() << endl;
    }
    else if(harta->isWalkable(newX, newY))
        player->setX(newX);
    break;
}
case 's':{
    int newX = player->getX();
    int newY = player->getY() + 1;
    Monster* mob = getMonsterAt(newX, newY);
    if(mob){
        mob->setHealth(mob->getHealth() - player->getDamage());
        cout << "Hit! Monster health: " << mob->getHealth() << endl;
    }
    else if(harta->isWalkable(newX, newY))
        player->setY(newY);
    break;
}
case 'd':{
    int newX = player->getX() + 1;
    int newY = player->getY();
    Monster* mob = getMonsterAt(newX, newY);
    if(mob){
        mob->setHealth(mob->getHealth() - player->getDamage());
        cout << "Hit! Monster health: " << mob->getHealth() << endl;
    }
    else if(harta->isWalkable(newX, newY))
        player->setX(newX);
    break;
}
        case 'l':running=false;break;

    }
}

void Game::update(){
    player->updateState();
    checkStairs();
    if(!running) 
        return;
    for(auto& mob: mobs){
        int oldX = mob->getX();
        int oldY = mob->getY();
        mob->updateState(player->getX(), player->getY());
        int dx = abs(mob->getX() - player->getX());
        int dy = abs(mob->getY() - player->getY());
        if(dx + dy == 1){
            player->setHealth(player->getHealth() - mob->getDamage());
        }
        if(!harta->isWalkable(mob->getX(), mob->getY())){
            mob->setX(oldX);
            mob->setY(oldY);
        }
    }

    mobs.erase(
        remove_if(mobs.begin(), mobs.end(),
            [](const unique_ptr<Monster>& m){ 
                return m->getHealth() <= 0; 
            }),
        mobs.end()
    );

    groundItems.erase(
        remove_if(groundItems.begin(), groundItems.end(),
            [&](GroundItem& gi){
                if(gi.x == player->getX() && gi.y == player->getY()){
                    gi.item->use(*player);  
                    player->getInventory().addItem(move(gi.item));
                    cout << "Picked up!" << endl;
                    return true;
                }
                return false;
            }),
        groundItems.end()
    );
}

void Game::render(){
    system("cls");
    harta->reset();
    harta->placeEntity(player->getX(), player->getY(), player->getSymbol());
    for(auto& mob : mobs)
        harta->placeEntity(mob->getX(), mob->getY(), mob->getSymbol());
    for(auto& gi : groundItems)  
        harta->placeEntity(gi.x, gi.y, string(1, gi.item->getSymbol()[0]));
vector<string> stats = {
    "=========================",
    "   Ramnicean's STATS   ",
    "=========================",
    "  HP  : " + to_string(player->getHealth()),
    " DMG : " + to_string(player->getDamage()),
    " SPD : " + to_string(player->getSpeed()),
    " LVS : " + to_string(player->getLives()),
    " SAN : " + to_string(player->getSanity()),
    "==================",
    "    INVENTORY     ",
    "=================="
};

for(int i = 0; i < player->getInventory().size(); i++){
    Item* item = player->getInventory().get(i);
    stats.push_back(" " + item->getItemName() + " +" + to_string(item->getStatBoost()));
}

stats.push_back("=========================");
stats.push_back(" Mobs: " + to_string(mobs.size()));
stats.push_back("=========================");
stats.push_back(" WASD = move      ");
stats.push_back(" L    = quit      ");
stats.push_back(" > = Dungeon's exit");
stats.push_back("=========================");
stats.push_back("Entities:");
stats.push_back("$ = Your character");
stats.push_back("C = Cersetor(enemy)");
stats.push_back(" F = Flamanzean(enemy)");
stats.push_back("=========================");
stats.push_back(" Items:");
stats.push_back(" X = Briceag");
stats.push_back(" B = Ciucas");

 auto& grid = harta->getGrid();
for(int i = 0; i < (int)grid.size(); i++){
    for(char c : grid[i]) cout << c;
    cout << "  ";
    if(i < (int)stats.size()) cout << stats[i];
    cout << "\n";
}
for(int i = (int)grid.size(); i < (int)stats.size(); i++){
    cout << string(grid[0].size() + 2, ' ') << stats[i] << "\n";
}
}

Monster* Game::getMonsterAt(int x, int y){
    for(auto& mob : mobs)
        if(mob->getX() == x && mob->getY() == y)
            return mob.get();
    return nullptr;
}

void Game::checkStairs(){
    if(harta->getTile(player->getX(), player->getY()) == '>'){
        running = false;
    }
}