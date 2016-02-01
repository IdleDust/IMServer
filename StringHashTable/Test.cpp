//
//  Test.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//

#include "Test.h"

void Test::testHashTable(){
    StringHashTable hashTable;
    while(1){
        cout<<"Please input an operation: ";
        string operation, word;
        cin>>operation>> word;
        if(operation[0] == 'i'){
            hashTable.insertWord(word);
        }
        else if(operation[0] == 'c'){
            cout<<word<<": "<<hashTable.countWord(word)<<endl;
        }
        else if(operation[0] == 'd'){
            hashTable.deleteWord(word);
            cout<<word<<": "<<hashTable.countWord(word)<<endl;
        }
        else{
            cout<<"Plese input a correct operation"<<endl;
        }
    }
}

void Test::testJMyStack(){
    string tmp;
    cout<<"Input [insert, pop, top, empty?] to begin:"<<endl;
    JMyStack<int> mystack;
    int x;
    while(1){
        cin>>tmp;
        if(tmp[0] == 'i'){
            cin>>x;
            mystack.push(x);
        }
        else if(tmp[0] == 'p'){
            mystack.pop();
        }
        else if(tmp[0]  == 't') {
            cout<<mystack.topElem()<<endl;
        }
        else if(tmp[0] == 'e'){
            cout<<mystack.isEmpty()<<endl;
        }
        else{
            cout<<"Pls choose from []."<<endl;
        }
    }
}

void Test::testLinearProbHashTable(){
    LinearProbHashTable hashTable;
    while(1){
        cout<<"Please input an operation: ";
        string operation, word;
        cin>>operation>> word;
        if(operation[0] == 'i'){
            hashTable.insertNode(word);
        }
        else if(operation[0] == 'c'){
            cout<<word<<": "<<hashTable.countNode(word)<<endl;
        }
        else if(operation[0] == 'd'){
            hashTable.deleteNode(word);
            cout<<word<<": "<<hashTable.countNode(word)<<endl;
        }
        else{
            cout<<"Plese input a correct operation"<<endl;
        }

    }
}

//void Test::testMyqueue(){
//    Myqueue<int> myqueue;
//    while(1){
//        cout<<"Input an operation:[push, pop, front, back, isempty]: ";
//        string operation;
//        int num;
//        cin>>operation>> num;
//        if(operation == "push"){
//            myqueue.push(num);
//        }
//        else if(operation == "pop"){
//            myqueue.pop();
//        }
//        else if(operation == "front"){
//            cout<<myqueue.frontOfQueue()<<endl;
//        }
//        else if(operation == "back"){
//            cout<<myqueue.backOfQueue()<<endl;
//        }
//        else if(operation == "isEmpty"){
//            cout<<myqueue.isEmpty()<<endl;
//        }
//        else{
//            cout<<"Plese input a correct operation"<<endl;
//        }
//    }
//}

void Test::testMyHeap(){
    MyHeap heap;
    while(1){
        cout<<"Input an operation:[insert, pop, display]: ";
        string operation;
        int num;
        cin>>operation;
        if(operation[0] == 'i'){
            cin>>num;
            heap.insert(num);
        }
        else if(operation[0] == 'p'){
            heap.pop();
        }
        else if(operation[0] == 'd'){
            heap.display();
        }
        else{
            cout<<"Plese input a correct operation"<<endl;
        }
    }
}

void Test::testMySegmentTree(){
    MySegmentTree tree;
    while(1){
        cout<<"Input an operation:[build, search, update]: ";
        string operation;
        int num;
        cin>>operation;
        if(operation[0] == 'b'){
            cout<<"Input n: ";
            cin>>num;
            int tmp;
            cout<<"input "<<num<<" numbers:";
            for(int i = 0; i < num; i++){
                cin>>tmp;
                tree.loc[i] = tmp;
            }
            tree.buildTree(1,0, num-1);
            tree.show();
        }
        else if(operation[0] == 's'){
            cout<<"Pls input a range[l, r]:";
            int l, r;
            cin>>l>>r;
            cout<<tree.searchNode(1,l,r)<<endl;
        }
        else if(operation[0] == 'u'){
            cout<<"Pls input [position, val]:";
            int p, val;
            cin>>p>>val;
            tree.updateNode(p, val);
            tree.show();
        }
        else{
            cout<<"Plese input a correct operation"<<endl;
        }
    }
}

void Test::testMyTopologicalSort(){
    TopologicalSort toposort;
    
    while(1){
        cout<<"Input an n index and m edges: ";
        int n, m;
        cin>>n>>m;
        toposort.createGraph(n, m);
        vector<int> ans = toposort.topoSort(n);
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
}


