//
//  MyStack.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef StringHashTable_MyStack_h
#define StringHashTable_MyStack_h

#include "includes.h"

template<class T>
class MyStack{
    
private:
    vector<T> myStack;
    int top;
    int stackSize;
    
public:
    
    MyStack(){
        top = -1;
        stackSize = 0;
        myStack.clear();
    }
    
    void push(T x){
        myStack.push_back(x);
        top++;
        stackSize++;
    }
    
    bool ifEmpty(){
        return top < 0;
    }
    
    void pop(){
        if(top < 0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        top--;
        stackSize--;
        myStack.pop_back();
        return;
    }
    
    T topElement(){
        return myStack[top];
    }
    
};

#endif
