#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "ServiceCenter.h"
#include "ListQueue.h"
#include "Office.h"
#include "Window.h"
#include "Customer.h"

using namespace std;


int main(int argc, char** argv){
    string input;
    input = argv[1];
    ServiceCenter<Customer<int>*> s = ServiceCenter<Customer<int>*>();
    cout<<"am I working?"<< endl;
    s.initiatSC(input);
    cout<<"am I working?"<< endl;
    s.simulation();
};