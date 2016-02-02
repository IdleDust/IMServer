//
//  SyncQueue.h
//  StringHashTable
//
//  Created by JuanChen on 16/1/19.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#ifndef __StringHashTable__SyncQueue__
#define __StringHashTable__SyncQueue__

#include "mySemaphore.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

template <class T>
class SyncQueue {
private:
    vector<T> q;
    int front;
    int rear;
    int qSize;
    MySemaphore *qSem;
    MySemaphore *avaiSlotsSem;
    MySemaphore *avaiItemsSem;
    
public:
    
    SyncQueue(int maxSize){
        qSize = maxSize;
        q.resize(qSize+2);
//        cout<<"qSize"<<q.size()<<endl;
        front = rear = 0;
        qSem = new MySemaphore(1);
        avaiSlotsSem = new MySemaphore(qSize);
        avaiItemsSem = new MySemaphore(0);
//        cout<<"qSem: "<<qSem<<endl;
//        cout<<"avaiSlotsSem: "<<avaiSlotsSem<<endl;
//        cout<<"avaiItemsSem: "<<avaiItemsSem<<endl;
//        cout<<"Queue created"<<endl;
        
    }
    
    void insertItem(T item){
//        cout<<"start"<<endl;
        avaiSlotsSem->pOperation();
//        cout<<"start"<<endl;
        
        qSem->pOperation();
        q[(++rear)%qSize] = item;
        qSem->vOperation();
        avaiItemsSem->vOperation();
    }
    
    T removeItem(){
        T item;
        avaiItemsSem->pOperation();
        qSem->pOperation();
        item = q[(++front)%qSize];
        qSem->vOperation();
        avaiSlotsSem->vOperation();
        return item;
    }
    int queueSize(){
        return abs(rear-front);
    }
    
};

#endif /* defined(__StringHashTable__SyncQueue__) */
