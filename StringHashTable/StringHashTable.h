//
//  StringHashTable.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef __StringHashTable__StringHashTable__
#define __StringHashTable__StringHashTable__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringHashTable{
    
private:
    int HashTableSize = 131;
    typedef struct node{
        string word;
        int count;
        node* next;
    }node;
    vector<node*> hashTable;
    int hashFunc(string word);
    
public:
    
    StringHashTable(){
        hashTable.resize(HashTableSize+2);
    }
    
    StringHashTable(int _size){
        HashTableSize = _size;
        hashTable.resize(HashTableSize+2);
    }
    
    ~StringHashTable(){
        hashTable.clear();
    }
    
    void insertWord(string word);
    int countWord(string word);
    void deleteWord(string word);
};

#endif /* defined(__StringHashTable__StringHashTable__) */
