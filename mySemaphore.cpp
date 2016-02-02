//
//  Semaphore.cpp
//  StringHashTable
//
//  Created by JuanChen on 16/1/19.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#include "mySemaphore.h"
#include <iostream>

using namespace std;

int MySemaphore::semCount = 0;

MySemaphore::MySemaphore(unsigned int val){
    semName = to_string(semCount++);
    //sem_unlink(semName.c_str());
    sem = sem_open(semName.c_str(), O_RDWR|O_CREAT, 0600, val);
    if(sem == SEM_FAILED) cout<<"Failed to initialize semaphore"<<endl;

//    int n = sem_init(&sem, 0, val);
//    if(n == -1) cout<<"Failed to initialize semaphore"<<endl;
//    cout<<"sem:"<<sem<<endl;
}

MySemaphore::MySemaphore(){
    MySemaphore(1);
}

int MySemaphore::pOperation(){
    return sem_wait(sem);
}

int MySemaphore::vOperation(){
    return sem_post(sem);
}

