//
//  StringHashTable.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#include "StringHashTable.h"

int StringHashTable::hashFunc(string word){
    int res = 1;
    for(int i = 0; i < word.length(); i++){
        //res = (res * (word[i]-'a')) % HashTableSize;
        res = (res + (word[i] - 'a'))%2;
    }
    return res;
}

void StringHashTable::insertWord(string word){
    int hashValue = hashFunc(word);
    node *listEnd = hashTable[hashValue];
    while(listEnd != NULL){
        if(listEnd->word == word){
            listEnd->count++;
            break;
        }
        else{
            listEnd = listEnd->next;
        }
    }
    if(listEnd == NULL){
        node *newWord = new node();
        newWord->word = word;
        newWord->count = 1;
        newWord->next = hashTable[hashValue]; ///why?
        hashTable[hashValue] = newWord; //why?
    }
}

int StringHashTable::countWord(string word){
    int hashValue = hashFunc(word);
    node *listEnd = hashTable[hashValue];
    while(listEnd != NULL){
        if(listEnd->word == word){
            break;
        }
        else{
            listEnd = listEnd->next;
        }
    }
    if(listEnd == NULL){
        return 0;
    }
    else{
        return listEnd->count;
    }
}

void StringHashTable::deleteWord(string word){
    
    int hashValue = hashFunc(word);
    node *cur = hashTable[hashValue];
    if(cur == NULL) {
        cout<<word<<" was not found"<<endl;
        return;
    }
    node *pre = NULL;
    while(cur != NULL){
        if(cur->word == word){
            cur->count--;
            if(cur->count == 0){
                if(pre == NULL){
                    node *tmp = cur;
                    cur = cur->next;
                    hashTable[hashValue] = cur;
                    delete tmp;
                }
                else{
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    return;
}

