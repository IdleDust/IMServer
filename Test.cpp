//
//  Test.cpp
//  StringHashTable
//
//  Created by JuanChen on 16/1/21.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#include "Test.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <thread>         // std::thread



void Test::testSyncQueue(){
    
    SyncQueue<int> syncQueue(5);
    
    const int WRITER_NUM = 5;
    const int READER_NUM = 5;
    
    Semaphore coutSem(1);
    
//    void writeQueue(){
//        while(1){
//            usleep(5000000);
//            int n = rand()%10;
//            if(n == 0) n++;
//            syncQueue.insertItem(n);
//            printf("Insert a number: %d\n", n);
//        }
//    }
//    
//    void readQueue(){
//        while(1){
//            usleep(1000000);
//            int n = syncQueue.removeItem();
//            printf("Get a number: %d\n", n);
//        }
//    }
    thread b(SyncQueue.readQueue);
    thread d(SyncQueue.readQueue);
    thread e(SyncQueue.readQueue);
    usleep(1000000);
    thread a(SyncQueue.writeQueue);
    
    b.join();
    //    c.join();
    d.join();
    e.join();
    usleep(1000000);
    a.join();
}