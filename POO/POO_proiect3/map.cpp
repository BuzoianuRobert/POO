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
    if(x < 0 || y < 0 || x >= height || y >= width)
        return false;
    if(grid[x][y] == ' ' || grid[x][y] == '>')
        return true;
    else
        return false;
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