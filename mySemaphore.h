//
//  Semaphore.h
//  StringHashTable
//
//  Created by JuanChen on 16/1/19.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#ifndef __StringHashTable__Semaphore__
#define __StringHashTable__Semaphore__

#include <semaphore.h>
#include <sys/sem.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

class MySemaphore{
private:
    string semName;
    static int semCount;
    sem_t *sem;

public:
    
    MySemaphore();
    MySemaphore(unsigned int val);
    int pOperation();
    int vOperation();
};

#endif /* defined(__StringHashTable__Semaphore__) */
