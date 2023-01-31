#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "ATStack.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;



template <typename W>
class fileProcessor{
public:
    fileProcessor();
    ~fileProcessor();
    void setInput(string input);
    string getInput();
    void setN(int n);
    int getN();
    void setP(int p);
    int getP();
    ATStack<double> processFile(string s, int size);

private:
    string m_input;
    int m_N; //rows
    int m_P; //columns

};

//Constructor

template <typename W>
fileProcessor<W>::fileProcessor(){
    m_input = "";
    m_N = 0;
    m_P = 0;

}

//Deconstructor
template <typename W>
fileProcessor<W>::~fileProcessor(){
    
}

//set/get

template <typename W>
string fileProcessor<W>::getInput(){
   return m_input; 
}

template <typename W>
void fileProcessor<W>::setInput(string input){
    m_input = input;
}

template <typename W>
int fileProcessor<W>::getN(){
    return m_N;
}

template <typename W>
void fileProcessor<W>::setN(int n){
    m_N = n;
}

template <typename W>
int fileProcessor<W>::getP(){
    return m_P;
}

template <typename W>
void fileProcessor<W>::setP(int p){
    m_P = p;
}


//Process text file and output an array (finding out N lines and P doubles)
template <typename W>
ATStack<double> fileProcessor<W>::processFile(string s, int size){
    ifstream inFile;
    ATStack<double> stack = ATStack<double>(size);
    inFile.open(s, ios::in | ios::binary);
    int count1 =0;
    int count2 =0;
    for(string line; getline(inFile, line);){
        string delimiter = " ";
        size_t pos = 0;
        string token;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            //cout << stod(token) << endl;
            stack.push(stod(token));
            line.erase(0, pos + delimiter.length());
        }
        count1 += 1;
        stack.push(stod(line));   
    }
    for(int i=0;i<stack.size();++i){
        count2 += 1;
    }
    count2 = (count2/count1);
    setN(count1);
    setP(count2);
    return stack;
}

#endif
