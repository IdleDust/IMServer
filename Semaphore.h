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

using namespace std;

class Semaphore{
private:
    sem_t *sem;
public:
    static string semName;

    Semaphore();
    Semaphore(unsigned int val);
    int pOperation();
    int vOperation();
};

#endif /* defined(__StringHashTable__Semaphore__) */
