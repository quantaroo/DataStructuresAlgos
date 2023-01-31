#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "ATStack.h"
#include "MonoStack.h"
#include "fileProcessor.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Obtain text file, place data into a stack, iterate through stack and place into new stack

template <typename V>
class SpeakerView{
public:
    SpeakerView();
    SpeakerView(string input, char type);
    ~SpeakerView();
    void setInput(string in);
    string getInput();
    int outputStack(string input);

private:
    string m_input;
    char m_type;
};

//constructor
template <typename V>
SpeakerView<V>::SpeakerView(){
    m_input = "";
    m_type = ' ';

}

template <typename V>
SpeakerView<V>::SpeakerView(string input, char type){
    m_input = input;
    m_type = type;
}

//deconstructor
template <typename V>
SpeakerView<V>::~SpeakerView(){
    
}

//set/get
template <typename V>
void SpeakerView<V>::setInput(string in){
    m_input = in;
}

template <typename V>
string SpeakerView<V>::getInput(){
    return m_input;
}


//Create stack and iterate through stack and place in monotonic order (input stack, input increasing/decreasing) (MonoStack.h) 
template <typename V>
int SpeakerView<V>::outputStack(string input){
    // MonoStack<double> mono = MonoStack<double>(input,'d',50);
    // mono.monotonic(input);
    return 1;
}

#endif