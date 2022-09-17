#include "Model.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*Model Class: Encode the rules of the Robber language*/

//Default constructor
Model::Model(){
    m_letter = ' ';
};

Model::Model(char letter){
    m_letter = letter;
};

//Setter and Getter
char Model::getLetter(){
    return m_letter;
}

void Model::setLetter(char l){
    m_letter = l;
}

//Default destructor
Model::~Model(){  
};

//translateSingleConsonant - takes a single consonant character as input and returns a string representing its encoding in Robert.

string Model::translateSingleConsonant(char l){
    if(l !='a'|| l !='e'|| l !='i'|| l !='o'|| l !='u'|| l !='A'|| l !='E'|| l !='I'|| l !='O'|| l !='U'||!(isalpha(l))){
        string rob = "";
        if(isupper(l)){
            string j(1,l);
            string k(1,(l + 32));
            rob += j + "o" + k;
            return rob;
        }
        else{
            string a(1,l);
            string rob = a + "o" + a;
            return rob;
        }
    }
    else{
        return "";
    }
};

//translateSingleVowel - takes a single vowel character as input and returns a string representing its encoding in Robert.

string Model::translateSingleVowel(char l){
    if(l =='a'||l =='e'||l =='i'||l =='o'||l =='u'||l =='A'||l =='E'||l =='I'||l =='O'||l =='U'||!(isalpha(l))){
        string letter(1,l);
        return letter;
    }
    else{
        return "";
    }
};