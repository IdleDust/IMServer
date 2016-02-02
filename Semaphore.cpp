//
//  Semaphore.cpp
//  StringHashTable
//
//  Created by JuanChen on 16/1/19.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#include "Semaphore.h"
#include <iostream>
using namespace std;

string mySemaphore::semName = "/tmp/mutex";

mySemaphore::mySemaphore(unsigned int val){
    semName[semName.length()-1]++;
    sem = sem_open(semName.c_str(), O_RDWR|O_CREAT, 0644, val);
//    int n = sem_init(sem, 0, val);
    if(sem == SEM_FAILED) cout<<"Failed to initialize semaphore"<<endl;
//    if(n == -1) cout<<"Failed to initialize semaphore"<<endl;
    cout<<sem<<endl;
}

mySemaphore::mySemaphore(){
    sem_init(sem, 0, 1);
}

int mySemaphore::pOperation(){
    return sem_wait(sem);
}

int mySemaphore::vOperation(){
    return sem_post(sem);
}

