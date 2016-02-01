//
//  SyncQueue.h
//  StringHashTable
//
//  Created by JuanChen on 16/1/19.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#ifndef __StringHashTable__SyncQueue__
#define __StringHashTable__SyncQueue__

#include "Semaphore.h"
#include <vector>

using namespace std;

template <class T>
class SyncQueue {
private:
    vector<T> q;
    int front;
    int rear;
    int qSize;
    Semaphore *qSem;
    Semaphore *avaiSlotsSem;
    Semaphore *avaiItemsSem;
    
public:
    
    SyncQueue(int maxSize){
        qSize = maxSize;
        q.resize(qSize+2);
        front = rear = 0;
        qSem = new Semaphore(1);
        avaiSlotsSem = new Semaphore(qSize);
        avaiItemsSem = new Semaphore(0);
    }
    
    void insertItem(T item){
        avaiSlotsSem->pOperation();
        qSem->pOperation();
        q[(++rear)%qSize] = item;
        qSem->vOperation();
        int n = avaiItemsSem->vOperation();
        printf("avai: %d\n", n);
    }
    
    T removeItem(){
        T item;
        int itemCount = avaiItemsSem->pOperation();
        printf("itemCount: %d\n", itemCount);
        qSem->pOperation();
        item = q[(++front)%qSize];
        qSem->vOperation();
        avaiSlotsSem->vOperation();
        return item;
    }
    
};

#endif /* defined(__StringHashTable__SyncQueue__) */
