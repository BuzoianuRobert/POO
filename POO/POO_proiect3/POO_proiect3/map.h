#ifndef MAP_H
#define MAP_H

#include<vector>
#include<string>

using namespace std;

class Map{
private:
    vector<vector<char>> grid;
    int width;
    int height;
    string filename;
public:
    Map(string mapa);
    bool isWalkable(int x,int y);
    void placeEntity(int x, int y, string symbol);
    void reset();
    char getTile(int x, int y);
    vector<vector<char>>& getGrid(){ return grid; }
    friend ostream& operator<<(ostream& out,const Map& obj);
};

#endif