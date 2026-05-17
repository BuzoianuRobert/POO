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
public:
    Map(string mapa);
    bool isWalkable(int x,int y);
    friend ostream& operator<<(ostream& out,const Map& obj);
};

#endif