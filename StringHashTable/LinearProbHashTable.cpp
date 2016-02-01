//
//  LinearProbHash.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#include "LinearProbHashTable.h"

int LinearProbHashTable::hashFunc(string s){
    int hashValue = 1;
    for(int i = 0; i <  s.length(); i++){
        hashValue = (hashValue * (s[0] - 'a')) % TABLE_SIZE;
    }
    return hashValue;
}

void LinearProbHashTable::insertNode(string s){
    int hashValue = hashFunc(s);
    if(hashTable[hashValue].ss == ""){
        hashTable[hashValue].ss = s;
        hashTable[hashValue].count = 1;
        
    }
    else{
        if(hashTable[hashValue].ss == s){
            hashTable[hashValue].count++;
        }
        else{
            while(hashValue < hashTable.size()){
                if(hashTable[hashValue].ss == s){
                    hashTable[hashValue].count++;
                    return;
                }
                else if(hashTable[hashValue].ss == ""){
                    hashTable[hashValue].ss = s;
                    hashTable[hashValue].count = 1;
                    return;
                }
                hashValue++;
            }
            hashValue = 0;
            int tmp = hashFunc(s);
            while(hashValue < tmp){
                if(hashTable[hashValue].ss == s){
                    hashTable[hashValue].count++;
                    return;
                }
                else if(hashTable[hashValue].ss == ""){
                    hashTable[hashValue].ss = s;
                    hashTable[hashValue].count = 1;
                    return;
                }
                hashValue++;
            }
        }
    }
}

int LinearProbHashTable::countNode(string s){
    int hashValue = hashFunc(s);
    if(hashTable[hashValue].ss == s) return hashTable[hashValue].count;
    else{
        for(int i = hashValue; i < TABLE_SIZE; i++){
            if(hashTable[i].ss == s){
                return hashTable[i].count;
            }
        }
        for(int i = 0; i < hashValue; i++){
            if(hashTable[i].ss == s){
                return hashTable[i].count;
            }
        }
        return 0;
    }
}


void LinearProbHashTable::deleteNode(string s){
    int hashValue = hashFunc(s);
    if(hashTable[hashValue].ss == s){
        hashTable[hashValue].count--;
        if(hashTable[hashValue].count == 0){
            hashTable[hashValue].ss = "";
            return;
        }
        return;
    }
    else{
        for(int i = hashValue; i < TABLE_SIZE; i++){
            if(hashTable[i].ss == s){
                hashTable[i].count--;
                if(hashTable[i].count == 0){
                    hashTable[i].ss = "";
                    return;
                }
                return;
            }
        }
        for(int i = 0; i < hashValue; i++){
            if(hashTable[i].ss == s){
                hashTable[i].count--;
                if(hashTable[i].count == 0){
                    hashTable[i].ss = "";
                    return;
                }
                return;
            }
        }
        cout<<s<<" was not found!"<<endl;
        return;
    }
}

