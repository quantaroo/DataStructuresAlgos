#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListQueue.h"
#include "ServiceCenter.h"
#include "Office.h"
#include "Window.h"
#include <cstdlib>
using namespace std;

template <typename U>
class Customer{
public:
    Customer();
    Customer(int num,int arrival);
    ~Customer();
    void setStudentNum(int num);
    int getStudentNum();
    void setArrival(int arrival);
    int getArrival();
    void setWaitCount(int count);
    int getWaitCount();
    void setDone(bool b);
    bool getDone();
    void setSlotTime(int pos, int min);
    int getSlotTime(int pos);
    void setOfficeTime(int pos, int office);
    int getOfficeTime(int pos);
    void adjustTime();

private:
    int m_studentnum;
    int m_arrival;
    int m_waitcounter;
    int m_slottimes[4];
    int m_offices[4];
    bool m_done;
};
//Constructors
template <typename U>
Customer<U>::Customer(){
    m_studentnum = 0;
    m_arrival = 0;
    m_waitcounter = 0;
    m_done = false;
}

template <typename U>
Customer<U>::Customer(int num,int arrival){
    m_studentnum = num;
    m_arrival = arrival;
    m_waitcounter = 0;
    m_done = false;
}

//Deconstructors
template <typename U>
Customer<U>::~Customer(){
    delete m_slottimes;
    delete m_offices;
}
//Getters-Setters
template <typename U>
void Customer<U>::setStudentNum(int num){
    m_studentnum = num;
}
template <typename U>
int Customer<U>::getStudentNum(){
    return m_studentnum;
}
template <typename U>
void Customer<U>::setArrival(int arrival){
    m_arrival = arrival;
}
template <typename U>
int Customer<U>::getArrival(){
    return m_arrival;
}
template <typename U>
void Customer<U>::setWaitCount(int count){
    m_waitcounter = count;
}
template <typename U>
int Customer<U>::getWaitCount(){
    return m_waitcounter;
}
template <typename U>
void Customer<U>::setDone(bool b){
    m_done = b;
}
template <typename U>
bool Customer<U>::getDone(){
    return m_done;
}
template <typename U>
void Customer<U>::setSlotTime(int pos, int min){
    m_slottimes[pos] = min;
}

template <typename U>
int Customer<U>::getSlotTime(int pos){
    return m_slottimes[pos];
}
template <typename U>
void Customer<U>::setOfficeTime(int pos, int office){
    m_offices[pos] = office;
}

template <typename U>
int Customer<U>::getOfficeTime(int pos){
    return m_offices[pos];
}
//Functions
//Adjust time left inside the slot time array.
template <typename U>
void Customer<U>::adjustTime(){
    if(getSlotTime(0)==0){
        if(getSlotTime(1)==0){
            if(getSlotTime(2)!=0){
                int set3 = getSlotTime(2);
                set3 -= 1;
                setSlotTime(2,set3);
            }
        }
        else{
            int set2 = getSlotTime(1);
            set2 -= 1;
            setSlotTime(1,set2);
        }
    }
    else{
        int set1 = getSlotTime(0);
        set1 -= 1;
        setSlotTime(0,set1);
    }
}


#endif