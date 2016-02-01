//
//  MySegmentTree.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/25.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef __StringHashTable__MySegmentTree__
#define __StringHashTable__MySegmentTree__

#include "includes.h"

class MySegmentTree{
private:
    typedef struct node{
        int maxVal;
        int maxIndex;
        int left, right;
    }node;
    
    vector<node> segmentTree;
    int SegmentTreeSize = 1331;

public:
    vector<int> loc;
    vector<int> inNodeNum;
    MySegmentTree(){
        segmentTree.resize(SegmentTreeSize);
        loc.resize(50);
        inNodeNum.resize(50);
    }
    
    ~MySegmentTree(){
        segmentTree.clear();
    }
    
    //void buildTree(int left, int right);
    void buildTree(int i, int left, int right);
    int searchNode(int root, int left, int right);
    void updateNode(int index, int curVal);
    void show();
    
};

#endif /* defined(__StringHashTable__MySegmentTree__) */
