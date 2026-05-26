#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "map.h"

using namespace std;

Map::Map(string mapa){
    ifstream fin(mapa);
    if(!fin.is_open()){
        cout << "Error: could not open file " << mapa << endl;
        return;
}
    height=0;
    string line;
    while(getline(fin,line)){
    grid.push_back(vector<char>(line.begin(), line.end()));       
    height++;
    }
    width=(int)grid[0].size();
};

bool Map::isWalkable(int x, int y){
    if(y < 0 || x < 0 || y >= height || x >= width)
        return false;
    return grid[y][x] != '#';
}

ostream& operator<<(ostream& out,const Map& obj){
    for(vector<char> x:obj.grid){
        for(char c:x){
            out<<c;
        }
        out<<endl;
    }
    return out;
}

void Map::placeEntity(int x, int y, string symbol){
    if(y >= 0 && y < height && x >= 0 && x < width)
        grid[y][x] = symbol[0];
}

void Map::reset(){
    grid.clear();
    height = 0;
    ifstream fin("mapa.txt");
    string line;
    while(getline(fin, line))
        grid.push_back(vector<char>(line.begin(), line.end()));
    height = grid.size();
    width = (int)grid[0].size();
}

char Map::getTile(int x, int y){
    if(y < 0 || x < 0 || y >= height || x >= width)
        return '#';
    return grid[y][x];
}