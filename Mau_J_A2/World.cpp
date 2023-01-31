#include "World.h"
#include "Mario.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


//Default constructor
World::World(){
    m_L = 0;
    m_N = 0;
    m_V = 0;
    m_end = 
    m_endL = 0;
    m_coin = 20;
    m_noth = 20;
    m_goom = 20;
    m_koop = 20;
    m_mush = 20;
    m_str = "";
    m_array = 0; //null
};

World::World(int L, int N, int V, int coin, int noth, int goom, int koop, int mush,string str){
    m_L = L;
    m_N = N;
    m_V = V;
    m_end = 0;
    m_endL = 0;
    m_coin = coin;
    m_noth = noth;
    m_goom = goom;
    m_koop = koop;
    m_mush = mush;
    m_str = str;
    //m_array[L][N][V];
    m_array = new char**[L*5];
    for(int i = 0; i < N*5; ++i){
        m_array[i] = new char*[N*5];
        for(int j = 0; j < V*5; ++j){
            m_array[i][j] = new char[V*5];
        }
    }
};

//Setter and Getter
int World::getL(){
    return m_L;
}

void World::setL(int Lvl){
    m_L = Lvl;
}

int World::getN(){
    return m_N;
}

void World::setN(int Nvl){
    m_N = Nvl;
}

int World::getV(){
    return m_V;
}

void World::setV(int Vvl){
    m_V = Vvl;
}

int World::getCoin(){
    return m_coin;
}

void World::setCoin(int c){
    m_coin = c;
}

int World::getNoth(){
    return m_noth;
}

void World::setNoth(int n){
    m_noth = n;
}

int World::getGoom(){
    return m_goom;
}

void World::setGoom(int g){
    m_goom = g;
}

int World::getKoop(){
    return m_koop;
}

void World::setKoop(int k){
    m_koop = k;
}

int World::getMush(){
    return m_mush;
}

int World::getEnd(){
    return m_end;
}

void World::setEnd(int end){
    m_end = end;
}

string World::getString(){
    return m_str;
}

void World::setString(string str){
    m_str = str;
}

char World::getChar(int i, int j, int k){
    return m_array[i][j][k];
}

void World::setChar(char ch, int i, int j, int k){
    m_array[i][j][k] = ch;
    
}

char*** World::getArray(){
    return m_array;
}


//Default destructor
World::~World(){  
};

//Function that sets up the world array for the level

void World::startArray(){

    //Initiate constant variables and counters
    int count = 0;
    int level = getL();
    int row = getN();
    int column = getV();
    int c = getCoin();
    int n = getCoin() + getNoth();
    int g = getCoin() + getNoth() + getGoom();
    int koo = getCoin() + getNoth() + getGoom() + getKoop();
    srand(time(0));
    srand((unsigned) time(0));

    //3D nested for loop that will populate the array
    for(int i = 0; i < level; ++i){
        for(int j = 0; j < row; ++j){
            for(int k = 0; k < column; ++k){

                //Distribute all the coins, nothing, goombas, koopas, and mushrooms uniformally

                int randnum = rand() % 100;
                if(randnum < c){
                    setChar('c',i,j,k);

                }
                else if((c <= randnum) && (n >randnum)){
                    setChar('x',i,j,k);
                }
                else if((n <= randnum) && (g > randnum)){
                    setChar('g',i,j,k);
                    
                }
                else if((g <= randnum) && (koo > randnum)){
                        setChar('k',i,j,k);
                }
                else{
                    setChar('m',i,j,k);
                }
            }
        }

        //Boss is set on every level 
        int randnum1 = rand() % row;
        int randnum2 = rand() % column;
        setChar('b' ,i , randnum1, randnum2);

        //Warp set for each level except last level
        if(i<(level-1)){
            int randnum3 = rand() % row;
            int randnum4 = rand() % column;
            setChar('w' ,i , randnum3, randnum4);
        }
    }
}

//==========================================================================================================================================================

//Play function where mario interacts with the array
void World::playGame(){
    ofstream outFile;
    outFile.open(getString(),ios::out | ios::app | ios::binary);
    Mario* ma = new Mario(getL(),getN(),getV(),0,1,0);
    srand(time(0));

    //Set initial position for mario 
    int level = 0;
    int killCount = 0;
    int randnum5 = rand() % getN();
    int randnum6 = rand() % getV();
    int fixedRow = getN();
    int fixedColumn= getV();     
    ma->setN(randnum5);
    ma->setV(randnum6);
    int row = ma->getN();
    int column = ma->getV();




    //While loop to move until last boss is defeated
    while(level<getL()){
        ofstream outFile;
        outFile.open(getString(),ios::out | ios::app | ios::binary);
        int condition = 0;
        bool win = 0;

        //while loop to move and compare on current level
        while(win==0){
            int randnum7 = rand() % 4;

            //Left -column
            if(randnum7 == 0){
                //Set the column 1 increment to the right
                if(column==0){
                    column += (getV()-1);
                    ma->setV(column);
                }
                else{
                    column = (column - 1);
                    ma->setV(column);
                }

                //Output required data to file at the new position
                outFile << "\nGoing Left <---\n======================" << endl;;
                for(int j = 0; j < getL(); ++j){
                    outFile << "\n\n";
                    outFile << "Level :";
                    outFile << (j);
                    outFile << "\n";
                    for(int k = 0; k < fixedRow; ++k){
                        for(int l = 0; l < fixedColumn; ++l){
                            if((j==level)&&(k==row)&&(l==column)){
                                outFile << "H";
                                outFile << " ";
                            }
                            else{
                                outFile << getChar(j,k,l);
                                outFile << " ";
                            }
                        }
                        outFile << "\n";
                    }
                }
                ma->output(level,getChar(level,row,column),getString());

                //Check condition of character of new position and output necessary information to file
                condition = ma->checkSpace(getChar(level,row,column),getString());

                //Make appropriate changes to the world given conditions (0=nothing,1=died,2=Defeat Boss,3=Warp,4=Kill Minion)
                if(condition == 0){
                    setChar('x',level,row,column);
                }
                else if(condition == 1){
                    exit(0);
                }
                else if(condition == 2){
                    setChar('x',level,row,column);
                    level += 1;
                    int randnum5 = rand() % getN();
                    int randnum6 = rand() % getV();     
                    ma->setN(randnum5);
                    ma->setV(randnum6);
                    int row = ma->getN();
                    int column = ma->getV();
                }
                else if(condition == 3){
                    setChar('x',level,row,column);
                    int randnum8 = (level+1) + rand() % (getL()-level-1);
                    level = randnum8;
                    win = 1;
                }
                else if(condition == 4){
                    killCount += 1;
                    if(killCount>6){
                        ma->setLife(ma->getLife()+1);
                        killCount = 0;
                    }
                    setChar('x',level,row,column);
                }
            }
            //==========================================================================================================================================================
            //Right +column
            else if(randnum7 == 1){

                //Set the column 1 increment to the right
                if(column==(getV()-1)){
                    column = 0;
                    ma->setV(column);
                }
                else{
                    column += 1;
                    ma->setV(column);
                }

                //Output required data to file at the new position
                outFile << "\nGoing Right --->\n======================" << endl;
                for(int j = 0; j < getL(); ++j){
                    outFile << "\n\n";
                    outFile << "Level :";
                    outFile << (j);
                    outFile << "\n";
                    for(int k = 0; k < fixedRow; ++k){
                        for(int l = 0; l < fixedColumn; ++l){
                            if((j==level)&&(k==row)&&(l==column)){
                                outFile << "H";
                                outFile << " ";
                            }
                            else{
                                outFile << getChar(j,k,l);
                                outFile << " ";
                            }
                        }
                        outFile << "\n";
                    }
                }
                ma->output(level,getChar(level,row,column),getString());

                //Check condition of character of new position and output necessary information to file
                condition = ma->checkSpace(getChar(level,row,column),getString());                                    
                
                //Make appropriate changes to the world given conditions (0=nothing,1=died,2=Defeat Boss,3=Warp,4=Kill Minion)
                if(condition == 0){
                    setChar('x',level,row,column);
                }
                else if(condition == 1){
                    exit(0);
                }
                else if(condition == 2){
                    setChar('x',level,row,column);
                    level += 1;
                    int randnum5 = rand() % getN();
                    int randnum6 = rand() % getV();     
                    ma->setN(randnum5);
                    ma->setV(randnum6);
                    int row = ma->getN();
                    int column = ma->getV();
                }
                else if(condition == 3){
                    setChar('x',level,row,column);
                    int randnum8 = (level+1) + rand() % (getL()-level-1);
                    level = randnum8;
                    win = 1;
                }
                else if(condition == 4){
                    killCount += 1;
                    if(killCount>6){
                        ma->setLife(ma->getLife()+1);
                        killCount = 0;
                    }
                    setChar('x',level,row,column);
                }
            }
            //==========================================================================================================================================================
            //Up -row
            else if(randnum7 == 2){

                //Set the column 1 increment to the right
                if(row==0){
                    row += (getN()-1);
                    ma->setN(row);
                }
                else{
                    row = row - 1;
                    ma->setN(row);
                }


                outFile << "\nGoing Up  ^^^^\n======================" << endl;
                for(int j = 0; j < getL(); ++j){
                    outFile << "\n\n";
                    outFile << "Level :";
                    outFile << (j);
                    outFile << "\n";
                    for(int k = 0; k < fixedRow; ++k){
                        for(int l = 0; l < fixedColumn; ++l){
                            if((j==level)&&(k==row)&&(l==column)){
                                outFile << "H";
                                outFile << " ";
                            }
                            else{
                                outFile << getChar(j,k,l);
                                outFile << " ";
                            }
                        }
                        outFile << "\n";
                    }
                }
                ma->output(level,getChar(level,row,column),getString());


                condition = ma->checkSpace(getChar(level,row,column),getString());

                //Make appropriate changes to the world given conditions (0=nothing,1=died,2=Defeat Boss,3=Warp,4=Kill Minion)
                if(condition == 0){
                    setChar('x',level,row,column);
                }
                else if(condition == 1){
                    exit(0);
                }
                else if(condition == 2){
                    setChar('x',level,row,column);
                    level += 1;
                    int randnum5 = rand() % getN();
                    int randnum6 = rand() % getV();     
                    ma->setN(randnum5);
                    ma->setV(randnum6);
                    int row = ma->getN();
                    int column = ma->getV();
                }
                else if(condition == 3){
                    setChar('x',level,row,column);
                    int randnum8 = level+1 + rand() % (getL()-level-1);
                    level = randnum8;
                    win =1;
                }
                else if(condition == 4){
                    killCount += 1;
                    if(killCount>6){
                        ma->setLife(ma->getLife()+1);
                        killCount = 0;
                    }
                    setChar('x',level,row,column);
                }
            }
            //==========================================================================================================================================================
            //Down +row
            else{
                
                //Set the column 1 increment to the right
                if(row==(getN()-1)){
                    row = 0;
                    ma->setN(row);
                }
                else{
                    row += 1;
                    ma->setN(row);
                }

                //Output required data to file at the new position
                outFile << "\nGoing Down vvvv\n=======================" << endl;
                for(int j = 0; j < getL(); ++j){
                    outFile << "\n\n";
                    outFile << "Level :";
                    outFile << (j);
                    outFile << "\n";
                    for(int k = 0; k < fixedRow; ++k){
                        for(int l = 0; l < fixedColumn; ++l){
                            if((j==level)&&(k==row)&&(l==column)){
                                outFile << "H";
                                outFile << " ";
                            }
                            else{
                                outFile << getChar(j,k,l);
                                outFile << " ";
                            }
                        }
                        outFile << "\n";
                    }
                }
                ma->output(level,getChar(level,row,column),getString());

                //Check condition of character of new position and output necessary information to file
                condition = ma->checkSpace(getChar(level,row,column),getString());

                //Make appropriate changes to the world given conditions (0=nothing,1=died,2=Defeat Boss,3=Warp,4=Kill Minion)
                if(condition == 0){
                    setChar('x',level,row,column);
                }
                else if(condition == 1){
                    exit(0);
                }
                else if(condition == 2){
                    setChar('x',level,row,column);
                    level += 1;
                    int randnum5 = rand() % getN();
                    int randnum6 = rand() % getV();     
                    ma->setN(randnum5);
                    ma->setV(randnum6);
                    int row = ma->getN();
                    int column = ma->getV();
                }
                else if(condition == 3){
                    setChar('x',level,row,column);
                    int randnum8 = (level+1) + rand() % (getL()-level-1);
                    level = randnum8;
                    win=1;
                }
                else if(condition == 4){
                    killCount += 1;
                    if(killCount>6){
                        ma->setLife(ma->getLife()+1);
                        killCount = 0;
                    }
                    setChar('x',level,row,column);
                }
            }
            if((condition==2)&&(level==getL())){
                win = 1;
                outFile << "\nMARIO WON!! YA! YA! YAAAHOOOO!\n";
            }
        }
        outFile.close();
    }

    delete ma;
}
