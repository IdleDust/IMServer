//
//  TopologicalSort.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/30.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#include "TopologicalSort.h"

void TopologicalSort::createGraph(int n, int m){
    int x, y;
        for(int i = 1; i <= m; i++){
        cout<<"input edge[x,y]:";
        cin>>x>>y;
        graph[x].push_back(y);
        if(count.find(y) != count.end()){
            count[y]++;
        }
        else count[y] = 1;
    }
}

vector<int> TopologicalSort::topoSort(int n){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(count.find(i) == count.end()){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int i = 0; i < graph[x].size(); i++){
            count[graph[x][i]]--;
            if(count[graph[x][i]] == 0) q.push(graph[x][i]);
        }
    }
    return ans;
}
