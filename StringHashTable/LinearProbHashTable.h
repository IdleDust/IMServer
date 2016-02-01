//
//  LinearProbHash.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef __StringHashTable__LinearProbHash__
#define __StringHashTable__LinearProbHash__

#include "includes.h"


class LinearProbHashTable{
private:
    const int TABLE_SIZE = 131;
    typedef struct node{
        string ss;
        int count;
    }node;
    vector<node> hashTable;
    int hashFunc(string s);
    
public:
    LinearProbHashTable(){
        hashTable.resize(TABLE_SIZE);
    }
    
    ~LinearProbHashTable(){
        hashTable.clear();
    }
    
    void insertNode(string s);
    void deleteNode(string s);
    int countNode(string s);
    
};

#endif /* defined(__StringHashTable__LinearProbHash__) */
