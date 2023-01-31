#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H

#include "ListQueue.h"
#include "Office.h"
#include "Window.h"
#include "Customer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename U>
class ServiceCenter{
public:
    ServiceCenter();
    ServiceCenter(string s);
    ~ServiceCenter();
    void setTimer(int time);
    int getTimer();
    void setInput(string input);
    string getInput();
    void setOffice(int pos, Office<U> office);
    Office<U> getOffice(int pos);
    void addCustomerO(U c);
    int getCustomerSizeO();
    U getFrontCustomerO();
    U removeCustomerO();
    void addCustomerD(U c);
    int getCustomerSizeD();
    U getFrontCustomerD();
    U removeCustomerD();
    void initiatSC(string input);
    void simulation();
    void studentTrafficOfficer();
private:
    int m_timer;
    string m_input;
    Office<U> m_officearray[100];
    ListQueue<U>* m_outsidequeue;
    ListQueue<U>* m_donequeue;
};

//Constructors
template <typename U>
ServiceCenter<U>::ServiceCenter(){
    m_timer = 0;
    m_input = "";
    m_outsidequeue = new ListQueue<U>();
    m_donequeue = new ListQueue<U>();
}

template <typename U>
ServiceCenter<U>::ServiceCenter(string input){
    m_timer = 0;
    m_input = input;
    m_outsidequeue = new ListQueue<U>();
    m_donequeue = new ListQueue<U>();
}
//Deconstructors
template <typename U>
ServiceCenter<U>::~ServiceCenter(){
    delete m_outsidequeue;
}

//Setters-Getters
template <typename U>
void ServiceCenter<U>::setTimer(int time){
    m_timer = time;
}
template <typename U>
int ServiceCenter<U>::getTimer(){
    return m_timer;
}

template <typename U>
void ServiceCenter<U>::setInput(string input){
    m_input = input;
}

template <typename U>
string ServiceCenter<U>::getInput(){
    return m_input;
}

template <typename U>
void ServiceCenter<U>::setOffice(int pos, Office<U> office){
    m_officearray[pos] = office;
}

template <typename U>
Office<U> ServiceCenter<U>::getOffice(int pos){
    return m_officearray[pos];
}

template <typename U>
void ServiceCenter<U>::addCustomerO(U c){
    m_outsidequeue->add(c);
}

template <typename U>
int ServiceCenter<U>::getCustomerSizeO(){
    return m_outsidequeue->size();
}

template <typename U>
U ServiceCenter<U>::getFrontCustomerO(){
    return m_outsidequeue->peek();
}

template <typename U>
U ServiceCenter<U>::removeCustomerO(){
    return m_outsidequeue->remove();
}
template <typename U>
void ServiceCenter<U>::addCustomerD(U c){
    m_donequeue->add(c);
}

template <typename U>
int ServiceCenter<U>::getCustomerSizeD(){
    return m_donequeue->size();
}

template <typename U>
U ServiceCenter<U>::getFrontCustomerD(){
    return m_donequeue->peek();
}

template <typename U>
U ServiceCenter<U>::removeCustomerD(){
    return m_donequeue->remove();
}

//Functions
//Initiate the service center
template <typename U>
void ServiceCenter<U>::initiatSC(string input){
    ifstream inFile;
    inFile.open(input, ios::in | ios::binary);
    Office<Customer<int>*> registrar = Office<Customer<int>*>();
    Office<Customer<int>*> cashier = Office<Customer<int>*>();
    Office<Customer<int>*> financial = Office<Customer<int>*>();
    int numLines=0;
    int arrival=0;
    int students=0;
    int student_count =1;
    int line_arrival=3;
    int line_students=4;
    string lines;
    while (getline(inFile, lines)){
        if(!lines.empty()){
            if(lines.size()<=3){
                if(numLines==0){ //number of windows in Register
                    int regi = stod(lines);
                    registrar.setWindow(regi);
                    for(int i=0;i<regi;++i){
                        Window<Customer<int>*>* wind = new Window<Customer<int>*>();
                        registrar.setWindowArray(i,wind);
                    }
                }
                else if(numLines==1){//number of windows in Cashier
                    int cashi = stod(lines);
                    cashier.setWindow(cashi);
                    for(int j=0;j<cashi;++j){
                        Window<Customer<int>*>* ca = new Window<Customer<int>*>();
                        cashier.setWindowArray(j,ca);
                    }
                }
                else if(numLines==2){//number of windows in Financial
                    int finan = stod(lines);
                    financial.setWindow(finan);
                    for(int k=0;k<finan;++k){
                        Window<Customer<int>*>* fi = new Window<Customer<int>*>();
                        financial.setWindowArray(k,fi);
                    }
                }
                else if(numLines==line_arrival){                 
                    arrival=stod(lines);
                }
                else{
                    students=stod(lines);
                    line_arrival+=students+2;
                    line_students+=students+2;
                }
            }
            else{
                Customer<int>* st = new Customer<int>(student_count,arrival);
                string delimiter = " ";
                size_t pos = 0;
                string token;
                st->setArrival(arrival);
                int count1 = 0;
                int count2 = 0;
                while ((pos = lines.find(delimiter)) != string::npos) {
                    token = lines.substr(0, pos);
                    if(token=="C"||token=="F"||token=="R"){
                        int office = 0;
                        if(token=="C"){
                            office = 1;
                        }
                        else if(token=="F"){
                            office = 2;
                        }
                        else if(token=="R"){
                            office = 3;
                        }
                        st->setOfficeTime(count2,office);
                        ++count2;
                    }
                    else{
                        st->setSlotTime(count1,stoi(token));
                        ++count1;
                    }
                    lines.erase(0, pos + delimiter.length());           
                }
                addCustomerO(st);
                ++student_count;
            }
            ++numLines;
        }
    }
    setOffice(0,cashier);
    setOffice(1,financial);
    setOffice(2,registrar);
    inFile.close();
    cout<<"am I working?"<< endl;
}

//Start simulation
template <typename U>
void ServiceCenter<U>::simulation(){
    cout<<"am I working?"<< endl;
    int timer = 0;
    int start = getCustomerSizeO();
    int end = getCustomerSizeD();
    while(start!=end){
        ++timer;

        setTimer(timer);
        //timers added to all those inside windows and queues.
        
        for(int j=0;j<3; ++j){
            int wind = getOffice(j).getWindow();
            for(int k=0;k<wind;++k){
                getOffice(j).adjustTimer(k);
                getOffice(j).checkAdjust(k); 
            }
            getOffice(j).WindowToDone();
            getOffice(j).customerToWindow();
        }
        studentTrafficOfficer();
        int end = getCustomerSizeD();
    }
    for(int n=0;n<3;++n){
        int w = getOffice(n).getCountW();
        for(int p=0;p<w;++p){
            cout<< getOffice(n).getWaitArray(p)<< " ";
        }
        cout<< " "<< endl;
        int idle = getOffice(n).getCountI();
        for(int q=0;q<idle;++q){
            cout<< getOffice(n).getIdleArray(q)<< " ";
        }
        cout<< " "<< endl;
    }
}
//Check student has arrived and place student into office
template <typename U>
void ServiceCenter<U>::studentTrafficOfficer(){
    if(getCustomerSizeO()!=0){
        //check the arrival students if they have arrived
        int s = getCustomerSizeO();
        for(int l=0; l<s;++l){
            Customer<int>* temp = removeCustomerO();
            if(temp->getArrival()==getTimer()){
                int office = temp->getOfficeTime(0);
                if(office == 1){
                    getOffice(0).addCustomerW(temp);
                }
                else if(office == 2){
                    getOffice(1).addCustomerW(temp);
                }
                else{
                    getOffice(2).addCustomerW(temp);
                }
            }
            else{
                addCustomerO(temp);
            }
        }
        //check the offices to see if there are any students in the done queue
        for(int m =0;m<3;++m){
            if(!(getOffice(m).isEmptyD())){
                Customer<int>* temp1 = getOffice(m).removeCustomerD();
                int slot1 = temp1->getSlotTime(0);
                int slot2 = temp1->getSlotTime(1);
                int slot3 = temp1->getSlotTime(2);
                if(slot1==0&&slot2!=0&&slot3!=0){
                    int next1 = temp1->getOfficeTime(1);
                    getOffice(next1).addCustomerW(temp1);
                }
                else if(slot1==0&&slot2==0&&slot3!=0){
                    int next2 = temp1->getOfficeTime(2);
                    getOffice(next2).addCustomerW(temp1);
                }
                else{
                    addCustomerD(temp1);
                }
                
            }
        }
    }
}
#endif