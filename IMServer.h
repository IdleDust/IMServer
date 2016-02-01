//
//  IMServer.h
//  StringHashTable
//
//  Created by JuanChen on 16/1/24.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#ifndef __StringHashTable__IMServer__
#define __StringHashTable__IMServer__

#include "includes.h"
#include <thread>
#include "SyncQueue.h"
#include "Semaphore.h"

//typedef void *(func)(void *);

#define BACKLOG 10
#define MYPORT 10000

class IMServer{
        
    static const int MAX_BUF;
    static map<int, int> IDtoFD;
    static map<int, int> IDtoDestID;
    static const int NUM_THREADS;
    static const int NUM_CLIENTS;
    
public:
    int sockfd;
    //int newfd[2];
    struct sockaddr_in server_addr, client_addr;
    
    IMServer();
    ~IMServer();
    void initSocket();
    void openListenFd();
    void connectClient();
    static void parseMsg(int newfd, const string &msg);
    static void newThread(const int* vargp);
    static void threadRead(const int* varp);
    static void threadWrite(const int* varp);
};


#endif /* defined(__StringHashTable__IMServer__) */
