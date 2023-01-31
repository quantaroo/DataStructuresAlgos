#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "World.h"
#include "Mario.h"

using namespace std;


int main(int argc, char** argv){
    //Obtain Inputs
    int arr[15];
    ifstream inFile;
    ofstream outFile;
    inFile.open(argv[1], ios::in | ios::binary);
    for(int i=0;i<8;++i){
        string line;
        getline(inFile,line);
        arr[i] = stoi(line);
    };

    //Start the Game :D
    World x = World(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],argv[2]);
    outFile.open(argv[2],ios::out | ios::binary);
    outFile << "MARIO STARTS HERE, LETS A GO!!";
    inFile.close();
    outFile.close();
    x.startArray();
    x.playGame();
};