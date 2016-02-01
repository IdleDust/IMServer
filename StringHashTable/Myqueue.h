////
////  Myqueue.h
////  StringHashTable
////
////  Created by JuanChen on 15/12/22.
////  Copyright (c) 2015年 Juan. All rights reserved.
////
//
//#ifndef StringHashTable_Myqueue_h
//#define StringHashTable_Myqueue_h
//
//#include "includes.h"
//
//template<class T>
//class Myqueue{
//    
//private:
//    
//    vector<T> myQueue;
//    int front;
//    int back;//last added item
//    int queueSize;
//    int maxSize = 31;
//   
//public:
//    
//    Myqueue(){
//        myQueue.resize(maxSize);
//        front = -1;
//        back = -1;
//        queueSize = 0;
//    }
//    
//    ~Myqueue(){
//        myQueue.clear();
//    }
//    
//    bool isEmpty(){
//        if(queueSize == 0) return true;
//        else return false;
//    }
//
//    
//    void push(T x){
//        if(queueSize == maxSize){
//            cout<<"Queque is full! Add failure!"<<endl;
//            return;
//        }
//        if(front == -1) front++;
//        back++;
//        if(back < maxSize){
//            myQueue[back] = x;
//            queueSize++;
//            return;
//        }
//        else{
//            int k = 0;
//            for(int i = front; i < back; i++){
//                myQueue[k] = myQueue[i];
//                k++;
//            }
//            front = 0;
//            back = k;
//            myQueue[back] = x;
//            queueSize++;
//            return;
//        }
//    }
//    
//    void pop(){
//        if(front == -1){
//            cout<<"Queue is Empty!"<<endl;
//            return;
//        }
//        cout<<myQueue[front]<<" Poped Out"<<endl;
//        front++;
//        return;
//    }
//    
//    T frontOfQueue(){
//        if(!isEmpty()){
//            return myQueue[front];
//        }
//        else
//    }
//    
//    T backOfQueue(){
//        if(!isEmpty()){
//            return myQueue[back];
//        }
//    }
//    
//};
//
//
//
//#endif
