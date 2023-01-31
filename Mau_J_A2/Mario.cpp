#include "Mario.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*Mario that interacts with the world.*/

//Default constructor
Mario::Mario(){
    m_L = 0;
    m_N = 0;
    m_V = 0;
    m_coin = 0;
    m_life = 1;
    m_power = 0;
};

Mario::Mario(int L, int N, int V, int coin, int life, int power){
    m_L = L;
    m_N = N;
    m_V = V;
    m_coin = coin;
    m_life = life;
    m_power = power;
};

//Setter and Getter
int Mario::getL(){
    return m_L;
}

void Mario::setL(int Lvl){
    m_L = Lvl;
}

int Mario::getN(){
    return m_N;
}

void Mario::setN(int Nvl){
    m_N = Nvl;
}

int Mario::getV(){
    return m_V;
}

void Mario::setV(int Vvl){
    m_V = Vvl;
}

int Mario::getCoin(){
    return m_coin;
}

void Mario::setCoin(int coin){
    m_coin = coin;
}

int Mario::getLife(){
    return m_life;
}

void Mario::setLife(int life){
    m_life = life;
}

int Mario::getPower(){
    return m_power;
}

void Mario::setPower(int power){
    m_power = power;
}

//Deconstructor
Mario::~Mario(){
    
};

//Function that takes a char returns an int (0-6) and updates Mario.
int Mario::checkSpace(char c, string s){
    //initialize filestream and check
    ofstream outFile;
    outFile.open(s,ios::out | ios::app | ios::binary);
    //Coin character results
    if(c=='c'){
        //If coin is at 19, Mario gains a life and Coins go back to 0
        if(getCoin()==19){
            setCoin(0);
            setLife(getLife()+1);
            outFile << "\nLive(s)  :";
            outFile << getLife();
            outFile << "\nCoin(s)  :";
            outFile << getCoin();
            outFile << "\nPower  :";
            outFile << getPower();
            return 0;
        }
        //Add a coin
        else{
            setCoin(getCoin()+1);
            outFile << "\nLive(s)  :";
            outFile << getLife();
            outFile << "\nCoin(s)  :";
            outFile << getCoin();
            outFile << "\nPower  :";
            outFile << getPower();
            return 0;
        }
    }
    //Nothing space
    else if(c=='x'){
        outFile << "\nLive(s)  :";
        outFile << getLife();
        outFile << "\nCoin(s)  :";
        outFile << getCoin();
        outFile << "\nPower  :";
        outFile << getPower();
        return 0;
    }

    //Goomba Character results
    else if(c=='g'){
        bool battle2 = 0;
        while(battle2 == 0){
            int randnum1 = rand() % 100;
            //If Mario Wins
            if((0< randnum1)&&(80>randnum1)){
                battle2 = 1;
                outFile << "\nMario fought a Goomba and won!" ;
                outFile << "\nLive(s)  :";
                outFile << getLife();
                outFile << "\nCoin(s)  :";
                outFile << getCoin();
                outFile << "\nPower  :";
                outFile << getPower();
                return 4;
            }
            //If Mario Losses
            else{
                //More power than 0
                if(getPower()>0){
                    setPower(getPower()-1);
                    outFile << "\nMario fought and powered down Oo.";
                    battle2 = 1;
                    outFile << "\nLive(s)  :";
                    outFile << getLife();
                    outFile << "\nCoin(s)  :";
                    outFile << getCoin();
                    outFile << "\nPower  :";
                    outFile << getPower();
                    return 0;

                }
                //If power is 0 or less but has a life
                else if((getPower()<=0)&&(getLife()>1)){
                    setLife(getLife()-1);
                    setPower(0);
                }
                //If power and life are both at the lowest limit, Mario dies
                else{
                    setLife(getLife()-1);
                    battle2 = 1;
                    outFile << "\nMario fought a Goomba and lost and died -_-" ;
                    outFile << "\nLive(s)  :";
                    outFile << getLife();
                    outFile << "\nCoin(s)  :";
                    outFile << getCoin();
                    outFile << "\nPower  :";
                    outFile << getPower();
                    outFile << "\n\n(>-_-)> MARIO DIED, MAMA MIA!(>-_-)>\n";
                    return 1;
                }
            }
        }
        
    }

    //Koopa character results
    else if(c=='k'){
        bool battle1 = 0;
        while(battle1 == 0){
            int randnum2 = rand() % 100;
            //If Mario Wins
            if((0< randnum2)&&(65>randnum2)){
                battle1 = 1;
                outFile << "\nMario fought a Koopa and won!" ;
                outFile << "\nLive(s)  :";
                outFile << getLife();
                outFile << "\nCoin(s)  :";
                outFile << getCoin();
                outFile << "\nPower  :";
                outFile << getPower();
                return 4;
            }
            //If Mario Losses
            else{
                //More power than 0
                if(getPower()>0){
                    setPower(getPower()-1);
                    outFile << "\nMario fought and powered down Oo.";
                    battle1 = 1;
                    outFile << "\nLive(s)  :";
                    outFile << getLife();
                    outFile << "\nCoin(s)  :";
                    outFile << getCoin();
                    outFile << "\nPower  :";
                    outFile << getPower();
                    return 0;
                }
                //If power is 0 or less but has a life
                else if((getPower()<=0)&&(getLife()>1)){
                    setLife(getLife()-1);
                    setPower(0);
                }
                //If power and life are both at the lowest limit, Mario dies
                else{
                    setLife(getLife()-1);
                    battle1 = 1;
                    outFile << "\nMario fought a Koopa and lost -_-" ;
                    outFile << "\nLive(s)  :";
                    outFile << getLife();
                    outFile << "\nCoin(s)  :";
                    outFile << getCoin();
                    outFile << "\nPower  :";
                    outFile << getPower();
                    outFile << "\n\n(>-_-)> MARIO DIED, MAMA MIA!(>-_-)>\n";
                    return 1;
                }
            }
        }
        
    }

    //Mushroom character results
    else if(c=='m'){
        //If mario has less than 2 power, add 1 power
        if(2>getPower()){
            int mushroom = getPower() + 1;
            setPower(mushroom);
            outFile << "\nLive(s)  :";
            outFile << getLife();
            outFile << "\nCoin(s)  :";
            outFile << getCoin();
            outFile << "\nPower  :";
            outFile << getPower();
            return 0;
        }
        //If mario has 2 power, do nothing
        else{
            return 0;
        }

    }

    //Boss character results
    else if(c=='b'){
        bool battle = 0;
        while(battle == 0){
            int randnum3 = rand() % 100;
            //If Mario Wins
            if((0< randnum3)&&(50>randnum3)){
                battle = 1;
                outFile << "\nMario fought a boss and won!" ;
                outFile << "\nLive(s)  :";
                outFile << getLife();
                outFile << "\nCoin(s)  :";
                outFile << getCoin();
                outFile << "\nPower  :";
                outFile << getPower();
                return 2;
            }
            //If Mario Losses
            else{
                //More power than 0
                if(getPower()>0){
                    setPower(getPower()-2);
                }
                //If power is 0 or less but has a life
                else if((getPower()<=0)&&(getLife()>1)){
                    setLife(getLife()-1);
                    setPower(0);
                }
                //If power and life are both at the lowest limit, Mario dies
                else{
                    setLife(getLife()-1);
                    battle = 1;
                    outFile << "\nMario fought the level boss and lost -_-";
                    outFile << "\nLive(s)  :";
                    outFile << getLife();
                    outFile << "\nCoin(s)  :";
                    outFile << getCoin();
                    outFile << "\nPower  :";
                    outFile << getPower();
                    outFile << "\n\n(>-_-)> MARIO DIED, MAMA MIA!(>-_-)>\n";
                    return 1;
                }
            }
        }
        
    }
    
    //Warp Character results
    else{ 
        outFile << "\nLive(s)  :";
        outFile << getLife();
        outFile << "\nCoin(s)  :";
        outFile << getCoin();
        outFile << "\nPower  :";
        outFile << getPower();
        return 3;

    }
    outFile.close();
    return 0;
}

//Output Mario's stats and location
void Mario::output(int i,char c, string s){
    //initiate filestream
    ofstream outFile;
    outFile.open(s,ios::out | ios::app | ios::binary);
    

    if(c == 'c'){

        outFile << "\nLevel  :";
        outFile << i;
        outFile << "\nRow  :";
        outFile << getN();
        outFile << "\nColumn  :";
        outFile << getV();
        outFile << "\nPower  :";
        outFile << getPower();
        outFile << "\nMario collected a coin!";
    }
    else if (c == 'x'){

        outFile << "\nLevel  :";
        outFile << i ;
        outFile << "\nRow  :";
        outFile << getN() ;
        outFile << "\nColumn  :";
        outFile << getV() ;
        outFile << "\nPower  :";
        outFile << getPower();
        outFile << "\nThe position is empty (>'.')> " ;
    }
    else if (c == 'g'){

        outFile << "\nLevel  :";
        outFile << i ;
        outFile << "\nRow  :";
        outFile << getN() ;
        outFile << "\nColumn  :";
        outFile << getV() ;
        outFile << "\nPower  :";
        outFile << getPower();
    }
    else if (c == 'k'){

        outFile << "\nLevel  :";
        outFile << i ;
        outFile << "\nRow  :";
        outFile << getN() ;
        outFile << "\nColumn  :";
        outFile << getV() ;
        outFile << "\nPower  :";
        outFile << getPower();
    }
    else if (c == 'b'){

        outFile << "\nLevel  :";
        outFile << i ;
        outFile << "\nRow  :";
        outFile << getN() ;
        outFile << "\nColumn  :";
        outFile << getV() ;
        outFile << "\nPower  :";
        outFile << getPower();
    }
    else if (c == 'm'){

        outFile << "\nLevel  :";
        outFile << i ;
        outFile << "\nRow  :";
        outFile << getN() ;
        outFile << "\nColumn  :";
        outFile << getV() ;
        outFile << "\nPower  :";
        outFile << getPower();
        outFile << "\nMario ate a mushroom!" ;
    }
    else if (c == 'w'){

        outFile << "\nLevel  :";
        outFile << i;
        outFile << "\nRow  :";
        outFile << getN() ;
        outFile << "\nColumn  :";
        outFile << getV() ;
        outFile << "\nPower  :";
        outFile << getPower();
        outFile << "\nMario Warps!" ;
    }
    else{
        outFile<< "\nMario Won!";
        exit(0);
    }
    outFile.close();
}
