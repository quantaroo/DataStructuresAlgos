#ifndef OFFICE_H
#define OFFICE_H

#include "ListQueue.h"
#include "Customer.h"
#include "Window.h"
#include "ServiceCenter.h"
#include <cstdlib>
using namespace std;


template <typename U>
class Office{
public:
    Office();
    Office(int windows);
    ~Office();
    void setTimer(int time);
    int getTimer();
    void setWaitArray(int pos, int wait);
    int getWaitArray(int pos);
    void setIdleArray(int pos, int idle);
    int getIdleArray(int pos);
    void setWindow(int window);
    int getWindow();
    void setCountW(int co);
    int getCountW();
    void setCountI(int count);
    int getCountI();
    void setWindowArray(int pos, Window<U>* window);
    Window<U>* getWindowArray(int pos);
    void addCustomerW(U c);
    bool isEmptyW();
    U getFrontCustomerW();
    U removeCustomerW();
    int sizeW();
    void addCustomerD(U c);
    bool isEmptyD();
    U getFrontCustomerD();
    U removeCustomerD();
    int sizeD();
    bool isWindowEmpty(int pos);
    void adjustTimer(int pos);
    void customerToWindow();
    void WindowToDone();
    void checkAdjust(int pos);

private:
    int m_timer;
    int m_windows;
    int m_waitcount;
    int m_idlecount;
    int m_waitarray[1000];
    int m_idlearray[1000];
    Window<U>* m_windowarray[1000];
    ListQueue<U>* m_waitqueue;
    ListQueue<U>* m_donequeue;
};
//Constructors
template <typename U>
Office<U>::Office(){
    m_timer = 0;
    m_windows = 0;
    m_waitcount = 0;
    m_idlecount = 0;
    m_waitqueue = new ListQueue<U>();
    m_donequeue = new ListQueue<U>();
}

template <typename U>
Office<U>::Office(int windows){
    m_timer = 0;
    m_windows = windows;
    m_waitcount = 0;
    m_idlecount = 0;
    m_waitqueue = new ListQueue<U>();
    m_donequeue = new ListQueue<U>();
}

//Deconstructors
template <typename U>
Office<U>::~Office(){
    delete m_waitqueue;
}

//Getters-Setters
template <typename U>
void Office<U>::setTimer(int time){
    m_timer = time;
}
template <typename U>
int Office<U>::getTimer(){
    return m_timer;
}
template <typename U>
void Office<U>::setWindow(int windows){
    m_windows = windows;
}
template <typename U>
int Office<U>::getWindow(){
    return m_windows;
}
template <typename U>
void Office<U>::setCountW(int co){
    m_waitcount = co;
}
template <typename U>
int Office<U>::getCountW(){
    return m_waitcount;
}
template <typename U>
void Office<U>::setCountI(int count){
    m_idlecount = count;
}
template <typename U>
int Office<U>::getCountI(){
    return m_idlecount;
}
template <typename U>
void Office<U>::setWaitArray(int pos, int wait){
    m_waitarray[pos] = wait;
}
template <typename U>
int Office<U>::getWaitArray(int pos){
    return m_waitarray[pos];
}
template <typename U>
void Office<U>::setIdleArray(int pos, int idle){
    m_idlearray[pos] = idle;
}
template <typename U>
int Office<U>::getIdleArray(int pos){
    return m_idlearray[pos];
}
template <typename U>
void Office<U>::setWindowArray(int pos, Window<U>* window){
    m_windowarray[pos] = window;
}
template <typename U>
Window<U>* Office<U>::getWindowArray(int pos){
    return m_windowarray[pos];
}
template <typename U>
void Office<U>::addCustomerW(U c){
    m_waitqueue->add(c);
}
template <typename U>
bool Office<U>::isEmptyW(){
    return m_waitqueue->isEmpty();
}
template <typename U>
U Office<U>::getFrontCustomerW(){
    return m_waitqueue->peek();
}
template <typename U>
U Office<U>::removeCustomerW(){
    return m_waitqueue->remove();
}
template <typename U>
int Office<U>::sizeW(){
    return m_waitqueue->size();
}
template <typename U>
void Office<U>::addCustomerD(U c){
    m_donequeue->add(c);
}
template <typename U>
bool Office<U>::isEmptyD(){
    return m_donequeue->isEmpty();
}
template <typename U>
U Office<U>::getFrontCustomerD(){
    return m_donequeue->peek();
}
template <typename U>
U Office<U>::removeCustomerD(){
    return m_donequeue->remove();
}
template <typename U>
int Office<U>::sizeD(){
    return m_donequeue->size();
}

//Functions
//Check if windows are empty
template <typename U>
bool Office<U>::isWindowEmpty(int pos){
    return getWindowArray(pos)->isEmpty();
}
//Adjust all the times under each window
template <typename U>
void Office<U>::adjustTimer(int pos){
    getWindowArray(pos)->addTimer();
    getWindowArray(pos)->adjustCustomer();
}
//add customer to open windows if open
template <typename U>
void Office<U>::customerToWindow(){
    int s = getWindow();
    for(int j=0;j<s;++j){
        if(!isEmptyW()){
            if(getWindowArray(j)->isEmpty()){
                Customer<int>* temp = removeCustomerW();
                //store wait count for customer
                int w = temp->getWaitCount();
                setWaitArray(getCountW(),w);
                w+=1;
                setCountW(w);
                //Store idle count for window
                int idlecount = getCountI();
                int idle = getWindowArray(j)->getIdleCount();
                setIdleArray(idlecount,idle);
                idlecount +=1;
                setCountI(idlecount);
                //Place customer into the window
                getWindowArray(j)->addCustomer(temp);
            }
        }
    }
}
//remove customer that are done at the window and place into done queue
template <typename U>
void Office<U>::WindowToDone(){
    int s = getWindow();
    for(int j=0;j<s;++j){
        if(!(getWindowArray(j)->isEmpty())){
            for(int k=0;k<3;++k){
                Customer<int>* temp = getWindowArray(j)->removeCustomer();
                if(temp->getSlotTime(k)==0){
                    addCustomerD(temp);
                }
                else{
                    getWindowArray(j)->addCustomer(temp);
                }
            }
        }
    }
}
//Check and adjust wait and idle times for window and Customer
template <typename U>
void Office<U>::checkAdjust(int pos){
    if(isWindowEmpty(pos)){
        int set = getWindowArray(pos)->getIdleCount();
        set += 1;
        getWindowArray(pos)->setIdleCount(set);
    }
    if(!(isEmptyW())){
        int size = sizeW();
        for(int i=0;i<size; ++i){
            Customer<int>* temp = removeCustomerW();
            int set2 = temp->getWaitCount();
            set2 += 1; 
            temp->setWaitCount(set2);
            addCustomerW(temp);
        }
    }
}

#endif