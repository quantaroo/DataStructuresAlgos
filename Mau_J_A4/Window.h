#ifndef WINDOW_H
#define WINDOW_H

#include "ListQueue.h"
#include "ServiceCenter.h"
#include "Customer.h"
#include <cstdlib>
using namespace std;

template <typename U>
class Window{
public:
    Window();
    ~Window();
    void setTimer(int time);
    int getTimer();
    void setIdleCount(int count);
    int getIdleCount();
    void addCustomer(U c);
    U getFrontCustomer();
    U removeCustomer();
    void addTimer();
    void adjustCustomer();
    bool isEmpty();
    
private:
    int m_timer;
    int m_idlecount;
    ListQueue<U>* m_windowslot;
};

//Constructors
template <typename U>
Window<U>::Window(){
    m_timer = 0;
    m_idlecount = 0;
    m_windowslot = new ListQueue<U>();
}
//Deconstructors
template <typename U>
Window<U>::~Window(){
    delete m_windowslot;
}

//Getters-Setters
template <typename U>
void Window<U>::setTimer(int time){
    m_timer = time;
}
template <typename U>
int Window<U>::getTimer(){
    return m_timer;
}
template <typename U>
void Window<U>::setIdleCount(int count){
    m_idlecount = count;
}
template <typename U>
int Window<U>::getIdleCount(){
    return m_idlecount;
}
template <typename U>
void Window<U>::addCustomer(U c){
    m_windowslot->add(c);
}
template <typename U>
U Window<U>::getFrontCustomer(){
    return m_windowslot->peek();
}
template <typename U>
U Window<U>::removeCustomer(){
    return m_windowslot->remove();
}

//Functions
//adjust time in window
template <typename U>
void Window<U>::addTimer(){
    m_timer += 1;
}
template <typename U>
void Window<U>::adjustCustomer(){
    getFrontCustomer()->adjustTime();
}
template <typename U>
bool Window<U>::isEmpty(){
    return m_windowslot->isEmpty();
}


#endif