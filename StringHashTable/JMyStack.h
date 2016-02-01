//
//  JMyStack.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef StringHashTable_JMyStack_h
#define StringHashTable_JMyStack_h

#include "includes.h"

template <class T>
class JMyStack{
private:
    int stackSize;
    vector<T> myStack;
    int top;

public:
    JMyStack(){
        stackSize = 0;
        top = -1;
    }
    
    ~JMyStack(){
        myStack.clear();
    }
    
    void push(T val){
        myStack.push_back(val);
        top++;
        stackSize++;
    }
    
    void pop(){
        if(stackSize < 0){
            cout<<"The Stack is empty!"<<endl;
            return;
        }
        else{
            myStack.pop_back();
            top--;
            stackSize--;
        }
    }
    bool isEmpty(){
        if(top < 0) return true;
        else return false;
    }
    
    T topElem(){
        return myStack[top];
    }
};



#endif
