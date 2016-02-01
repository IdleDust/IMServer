//
//  TopologicalSort.h
//  StringHashTable
//
//  Created by JuanChen on 15/12/30.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#ifndef __StringHashTable__TopologicalSort__
#define __StringHashTable__TopologicalSort__

#include "includes.h"

class TopologicalSort{
private:
    vector<vector<int> > graph;
    unordered_map<int,int> count;
    vector<int> ans;
    int maxN = 131;

public:
    void createGraph(int n, int m);//n个点，m条边
    vector<int> topoSort(int n);
    
    TopologicalSort(){
        graph.resize(maxN);
    }
    
    ~TopologicalSort(){
        ans.clear();
        graph.clear();
    }
};


#endif /* defined(__StringHashTable__TopologicalSort__) */
