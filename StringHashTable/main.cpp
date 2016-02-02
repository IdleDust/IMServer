//
//  main.cpp
//  StringHashTable
//
//  Created by JuanChen on 15/12/20.
//  Copyright (c) 2015年 Juan. All rights reserved.
//
//-----------------start--------------------------------------
//#include "SyncQueue.h"
//#include <unistd.h>
//#include <cstdlib>
//#include <iostream>
//#include <thread>
//
//SyncQueue<int> syncQueue(5);
//
//const int WRITER_NUM = 5;
//const int READER_NUM = 5;
//
//MySemaphore coutSem(1);
//
//void writeQueue(){
//    while(1){
//        usleep(500000);
//        int n = rand()%10;
//        if(n == 0) n++;
//        syncQueue.insertItem(n);
//        printf("Insert a number: %d\n", n);
//        cout<<"QueueSize: "<<syncQueue.queueSize()<<endl;
//    }
//}
//
//void readQueue(){
//    while(1){
//        usleep(1000000);
//        int n = syncQueue.removeItem();
//        printf("Get a number: %d\n", n);
//        cout<<"QueueSize: "<<syncQueue.queueSize()<<endl;
//    }
//}
//
//void test(){
//    thread b(writeQueue);
//    thread d(writeQueue);
//    thread e(writeQueue);
//    usleep(1000000);
//    thread a(readQueue);
//    
//    b.join();
//    //    c.join();
//    d.join();
//    e.join();
//    usleep(1000000);
//    a.join();
//}
//
//int main(int argc, const char * argv[])
//{
//    test();
//    return 0;
//}
//------------------------end------------------------------
//
//

#include "../IMServer.h"

int main(){
    IMServer server;
    server.initSocket();
    server.openListenFd();
    server.connectClient();
    return 0;
}
