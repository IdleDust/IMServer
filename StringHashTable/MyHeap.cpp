//
//  MyHeap.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/24.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#include "MyHeap.h"

int MyHeap::parent(int t){
    return t/2;
}

int MyHeap::rightChild(int t){
    if((2*t+1) <= heapSize) {
        return 2*t+1;
    }
    else return 0;
}

int MyHeap::leftChild(int t){
    if((2*t) <= heapSize){
        return 2*t;
    }
    else return 0;
}

bool MyHeap::isEmpty(){
    return heapSize < 1;
}

void MyHeap::display(){
    if(isEmpty()) cout<<"The heap is Empty."<<endl;
    else{
        cout<<"Heap:";
        for(int i = 1; i <= heapSize; i++){
            cout<<" "<<myheap[i];
        }
        cout<<endl;
    }
}

void MyHeap::insert(int x){
    heapSize++;
    int cur = heapSize;
    myheap[cur] = x;
    while(parent(cur) > 0){
        if(myheap[parent(cur)] < myheap[cur]){
            swap(myheap[cur], myheap[parent(cur)]);
            cur = parent(cur);
        }
        else break;
    }
    display();
}

int MyHeap::max(int x, int y){
    return x > y ? x : y;
}

int MyHeap::pop(){
    if(heapSize == 0) {
        cout<<"Heap is Empty. Failed to proceed."<<endl;
        return -1;
    }
    int res = myheap[1];
    myheap[1] = myheap[heapSize];
    heapSize--;
    int cur = 1;
    int l = leftChild(cur);
    int r = rightChild(cur);
    int tag;
    while(l != 0 || r != 0){
        if(l != 0 && r != 0){
            int tmp = max(myheap[l], myheap[r]);
            if(myheap[cur] < tmp){
                if(myheap[l] == tmp) tag = l;
                else tag = r;
                swap(myheap[cur], myheap[tag]);
                cur = tag;
            }
        }
        else if(l == 0){
            if(myheap[cur] < myheap[r]){
                swap(myheap[cur], myheap[r]);
                cur = r;
            }
        }
        else if(r == 0){
            if(myheap[cur] < myheap[l]){
                swap(myheap[cur], myheap[l]);
                cur = l;
            }
            else break;
        }
        l = leftChild(cur);
        r = rightChild(cur);
    }
    cout<<"Outside loop:";
    display();
    return res;
}
