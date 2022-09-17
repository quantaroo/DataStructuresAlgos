#ifndef MODEL_H
#define MODEL_H

#include <string>
using namespace std;

/*Model Class: Encode the rules of the Robber language*/

class Model{
public:
    Model();
    Model(char letter);
    virtual ~Model();
    string translateSingleConsonant(char l);
    string translateSingleVowel(char l);
    char getLetter();
    void setLetter(char l);
private:
    char m_letter;
};

#endif