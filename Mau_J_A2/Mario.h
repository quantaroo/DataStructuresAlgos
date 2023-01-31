#ifndef MARIO_H
#define MARIO_H

#include <string>
using namespace std;

/*Mario that interacts with the world.*/

class Mario{
public:
        Mario();
        Mario(int L, int N, int V, int coin, int life, int power);
        virtual ~Mario();
        int getL();
        void setL(int Lvl);
        int getN();
        void setN(int Nvl);
        int getV();
        void setV(int Vvl);
        int getCoin();
        void setCoin(int coint);
        int getLife();
        void setLife(int life);
        int getPower();
        void setPower(int power);
        int checkSpace(char c, string s);
        void output(int i,char c, string s);
    private:
        int m_L;
        int m_N;
        int m_V;
        int m_coin;
        int m_life;
        int m_power;

};

#endif