#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"
#include <string>
using namespace std;

/*Translator Class: Translate English sentences to Rovarspraket sentences using the Model class. */

class Translator{
public:
    Translator();
    Translator(string s);
    virtual ~Translator();
    string translateEnglishWord(string w);
    string translateEnglishSentence(string s);
    string getSentence();
    void setSentence(string sent);
private:
    string m_sentence;
    Model* m_model;
};

#endif