#ifndef MONOSTACK_H
#define MONOSTACK_H

#include "ATStack.h"
#include "fileProcessor.h"
#include "SpeakerView.h"
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename U>
class MonoStack{
public:
    MonoStack();
    MonoStack(string input, char t, int si);
    ~MonoStack();
    void setInput(string input);
    string getInput();
    void setType(char type);
    int getType();
    void setSize(int size);
    int getSize();
    void setN(int n);
    int getN();
    void setP(int p);
    int getP();
    ATStack<double> monotonic(string s);
    ATStack<double> createStack(ATStack<double> stack);

private:
    string m_input;
    char m_type;
    int m_size;
    int m_N; //rows
    int m_P; //columns

};

//Constructor
template <typename U>
MonoStack<U>::MonoStack(){
    m_input = "";
    m_type = ' ';
    m_size = 0;
    m_N = 0;
    m_P = 0;

}

template <typename U>
MonoStack<U>::MonoStack(string input, char t, int si){
    m_input = input;
    m_type = t;
    m_size = si;
    m_N = 0;
    m_P = 0;

}

//Deconstructor
template <typename U>
MonoStack<U>::~MonoStack(){
    //m_stack.~ATStack();
}

//set-get
template <typename U>
void MonoStack<U>::setInput(string input){
    m_input = input;
}

template <typename U>
string MonoStack<U>::getInput(){
    return m_input;
}

template <typename U>
void MonoStack<U>::setType(char type){
    m_type = type;
}

template <typename U>
int MonoStack<U>::getType(){
    return m_type;
}

template <typename U>
void MonoStack<U>::setSize(int size){
    m_size = size;    
}

template <typename U>
int MonoStack<U>::getSize(){
    return m_size;
}
template <typename U>
void MonoStack<U>::setN(int n){
    m_N = n;    
}

template <typename U>
int MonoStack<U>::getN(){
    return m_N;
}
template <typename U>
void MonoStack<U>::setP(int p){
    m_P = p;    
}

template <typename U>
int MonoStack<U>::getP(){
    return m_size;
}

//monotonic stack processor (input is text file)
template <typename U>
ATStack<double> MonoStack<U>::monotonic(string s){
    fileProcessor<string> f = fileProcessor<string>();
    ATStack<double> g = f.processFile(s,m_size);
    setN(f.getN()); //row
    setP(f.getP()); //column

    //increasing monotonically
    if(m_type == 'i'){
        ATStack<double> temp = ATStack<double>(m_P);
        for(int j=0; j<m_P; ++j){
            for(int k=(0+j); k<(m_P*m_N); k+=m_P){
                temp.push(g.getDouble(k));
                //cout<< g.getDouble(k) << endl;
            }
            for(int i=0;i<(m_N);++i){
                cout<< temp.pop()<< endl;
            }
            cout<< "break" << endl;
        }
        return g;
        
    }

    //decreasing monotonically
    else if(m_type == 'd'){
        ATStack<double> temp = ATStack<double>(m_P);
        ATStack<double> fin = ATStack<double>(m_P);
        for(int j=0; j<m_P; ++j){
            for(int k=(0+j); k<(m_P*m_N); k+=m_P){
                temp.push(g.getDouble(k));
                //cout<< g.getDouble(k) << endl;
            }

            for(int l=0;l<m_P;++l){
                while (!temp.isEmpty()&&(temp.peek()<temp.getDouble(l))){
                    temp.pop();
                }
                
            }
            cout<< "In column ";
            cout<< j;
            cout<< ", the people that can see have the height of: ";
            int count = 0;
            for(int i=0;i<(m_N);++i){
                double var = temp.pop();
                if(var>1.0){
                    cout<< var;
                    cout<< " ";
                    count+=1;
                }
            }
            cout<< "inches.";
            cout<< " A total of ";
            cout<< count << endl;
            
        }
        return g;
    }
    else{
        exit(0);
    }
}

//make stack and check for duplecates
// template <typename U>
// ATStack<double> MonoStack<U>::createStack(ATStack<double> stack){
    
// }

#endif