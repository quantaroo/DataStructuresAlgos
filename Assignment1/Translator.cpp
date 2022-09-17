#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*Translator Class: Translate English sentences to Rovarspraket sentences using the Model class. */

//Default constructor
Translator::Translator(){
    m_sentence = "";
};
Translator::Translator(string s){
    m_sentence = s;
    
}
//Default destructor
Translator::~Translator(){
    if(m_model != NULL){
        delete m_model;
    }
};

//Setter and Getter
string Translator::getSentence(){
    return m_sentence;
}

void Translator::setSentence(string sent){
    m_sentence = sent;
}

//translateEnglishWord - takes a single string representing a single English word as input and returns a string representing the Robert translation.
string Translator::translateEnglishWord(string w){
    string robWord = "";
    for(int i = 0; i<w.length(); ++i){
        Model* x = new Model(w[i]);
        char z = x->getLetter();
        if(z =='a'||z =='e'||z =='i'||z =='o'||z =='u'||z =='A'||z =='E'||z =='I'||z =='O'||z =='U'||!(isalpha(z))){ 
            robWord += x->translateSingleVowel(z);
        }
        else{
            robWord += x->translateSingleConsonant(z);
        }
        delete x;
    }
    return robWord;

}

//translateEnglishSentence - takes a single string representing a single English sentence as input and returns a string representing the Robert translation.
string Translator::translateEnglishSentence(string s){
    string robSent = "";
    string sentence;
    int count = 0;
    int set = 0;
    for(int i = 0; i<s.length(); ++i){
        if(s[i]== ' '||s[i]=='!'||s[i]=='.'||s[i]=='?'||s[i]=='\n'){
            string word = "";
            for(int j = 0; j < ((count)-set); ++j){
                string d(1,s[set+j]);
                word += d; 
            }
            sentence += translateEnglishWord(word);
            set = i;
        }
        count++;
    }
    //Just in case the last sentence does not have a punctuation, I have left a html code catch all.
    robSent += "<br>";
    robSent += "<i>" + sentence + "</i>";
    robSent += "<br>";
    return robSent;
}