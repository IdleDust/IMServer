//
//  MySegmentTree.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/25.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#include "MySegmentTree.h"

int max(int x, int y){
    return x > y ? x : y;
}

void MySegmentTree::show(){
    cout<<"Show:"<<endl;
    for(int i = 0; i < 2*loc.size()-1; i++){
        cout<<'['<<segmentTree[i].left<<','<<segmentTree[i].right<<']'<<segmentTree[i].maxVal<<endl;
    }
}

void MySegmentTree::buildTree(int i, int left, int right){
    segmentTree[i].left = left;
    segmentTree[i].right = right;
    segmentTree[i].maxIndex = 0;
    segmentTree[i].maxVal = 0;
    if(left == right){
        segmentTree[i].maxIndex = left;
        segmentTree[i].maxVal = loc[left];
        inNodeNum[left] = i;
        return;
    }
    buildTree(i*2, left, (left+right)/2);
    buildTree(i*2+1, (left+right)/2+1, right);
    if(loc[segmentTree[i*2].maxIndex] >= loc[segmentTree[i*2+1].maxIndex]){
        segmentTree[i].maxIndex = segmentTree[i*2].maxIndex;
        segmentTree[i].maxVal = segmentTree[i*2].maxVal;
    }
    else{
        segmentTree[i].maxVal = segmentTree[i*2+1].maxVal;
        segmentTree[i].maxIndex = segmentTree[i*2+1].maxIndex;
    return;
    }
}

int MySegmentTree::searchNode(int root, int left, int right){
    if(left == segmentTree[root].left && right == segmentTree[root].right){
        return segmentTree[root].maxVal;
    }
    int mid = (segmentTree[root].left + segmentTree[root].right)>>1;
    if(right <= mid) return searchNode(root*2, left, right);
    else if(left > mid) return searchNode(root*2+1, left, right);
    else{
        return max(searchNode(root*2, left, mid),
                   searchNode(root*2+1, mid+1, right));
    }
    return 0;
}

void MySegmentTree::updateNode(int index, int curVal){
    if(curVal == loc[index]) return;
    loc[index] = curVal;
    int idx = inNodeNum[index];
    segmentTree[idx].maxVal = curVal;
    if(idx % 2 == 0){
        while(idx/2 > 0){
            if(segmentTree[idx].maxVal >= segmentTree[idx+1].maxVal){
                segmentTree[idx/2].maxVal = segmentTree[idx].maxVal;
                segmentTree[idx/2].maxIndex = segmentTree[idx].maxIndex;
            }
            else{
                segmentTree[idx/2].maxVal = segmentTree[idx+1].maxVal;
                segmentTree[idx/2].maxIndex = segmentTree[idx+1].maxIndex;
            }
            idx = idx/2;
        }
    }
    else{
        while(idx/2 > 0){
            if(segmentTree[idx].maxVal >= segmentTree[idx-1].maxVal){
                segmentTree[idx/2].maxVal = segmentTree[idx].maxVal;
                segmentTree[idx/2].maxIndex = segmentTree[idx].maxIndex;
            }
            else{
                segmentTree[idx/2].maxVal = segmentTree[idx-1].maxVal;
                segmentTree[idx/2].maxIndex = segmentTree[idx-1].maxIndex;
            }
            idx = idx/2;
        }
    }
}


//void MySegmentTree::buildTree(int left, int right){
//    buildTree(1,left,right);
//    show();
//}

