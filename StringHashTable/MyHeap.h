//
//  MyHeap.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/24.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef __StringHashTable__MyHeap__
#define __StringHashTable__MyHeap__

#include "includes.h"

class MyHeap{
private:
    
    vector<int> myheap;
    int maxHeapSize = 331;
    int heapSize;
    
public:
    
    MyHeap(){
        myheap.resize(maxHeapSize);
        heapSize = 0;
    }
    
    ~MyHeap(){
        myheap.clear();
        heapSize = 0;
    }
    
    int parent(int t);
    int rightChild(int t);
    int leftChild(int t);
    bool isEmpty();
    int max(int x, int y);
    
    void insert(int x);
    int pop();
    void display();
};

#endif /* defined(__StringHashTable__MyHeap__) */
