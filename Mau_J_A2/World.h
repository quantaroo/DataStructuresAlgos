#ifndef WORLD_H
#define WORLD_H

#include <string>
using namespace std;

/*Contains the environment(array of levles LxNxV), objects inside of the array.*/

class World{
    public:
        World();
        World(int L, int N, int V, int coin, int noth, int goom, int koop, int mush, string str);
        virtual ~World();
        int getL();
        void setL(int Lvl);
        int getN();
        void setN(int Nvl);
        int getV();
        void setV(int Vvl);
        int getCoin();
        void setCoin(int c);
        int getNoth();
        void setNoth(int n);
        int getGoom();
        void setGoom(int g);
        int getKoop();
        void setKoop(int k);
        int getMush();
        void setMush(int m);
        int getEnd();
        void setEnd(int end);
        string getString();
        void setString(string s);
        char getChar(int i, int j, int k);
        void setChar(char ch, int i, int j, int k);
        char*** getArray();
        void startArray();
        void playGame();



    private:
        int m_L;
        int m_N;
        int m_V;
        int m_coin;
        int m_noth;
        int m_goom;
        int m_koop;
        int m_mush;
        int m_end;
        int m_endL;
        string m_str;
        char*** m_array;
};

#endif