//
//  IMServer.cpp
//  StringHashTable
//
//  Created by JuanChen on 16/1/24.
//  Copyright (c) 2016年 Juan. All rights reserved.
//

#include "IMServer.h"

const int IMServer::MAX_BUF = 1000;
const int IMServer::NUM_THREADS = 2;
const int IMServer::NUM_CLIENTS = 255;

map<int, int> IMServer::IDtoFD = map<int,int>();
//map<int, int> IMServer::IDtoDestID = map<int, int>();

SyncQueue<string> IMServer::mQueue(255);

IMServer::IMServer(){

}

IMServer::~IMServer(){

}

void IMServer::initSocket(){
    sockfd = 1;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("Socket");
        exit(1);
    }
    cout<<"Creat socket success"<<endl;
}

void IMServer::openListenFd(){
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(MYPORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(&(server_addr.sin_zero),8);
    
    int res = ::bind(sockfd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in));
    if(res == -1){
        perror("bind");
        exit(1);
    }
    cout<<"bind succeed"<<endl;
    
    res = listen(sockfd, BACKLOG);
    if(res == -1){
        perror("Listen");
        exit(1);
    }
    cout<<"listen on port 10000"<<endl;
}

void IMServer::connectClient(){
    int newfd[NUM_CLIENTS];
    thread t[NUM_CLIENTS];
    int sin_size = sizeof(struct sockaddr_in);
    for(int i = 0; i < NUM_CLIENTS; i++){
        cout<<"i= "<<i<<endl;
        newfd[i] = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&sin_size);
        cout<<"newfd[i] = "<<newfd[i]<<endl;
        if(newfd[i] != 0){
           cout<<"Receive a client"<<endl;
        }
        else{
            cout<<"Error"<<endl;
            return;
        }
        cout<<newfd[i]<<endl;
        t[i] = thread(newThread, &newfd[i]);
        //t[i].join();
//    while(true){
//        usleep(1000000);
//    }
    
//    while(true){
//        memset(buf, 0, sizeof(buf));
//        res = (int)read(newfd, buf, 255);
//        if(res == -1){
//            perror("recv()");
//            exit(1);
//        }
//        printf("recv data: %s\n", buf);
//    }
    }
}

void IMServer::newThread(const int* vargp){
    cout<<"Thread created"<<endl;
    int fd = *((int *)vargp);
    cout<<fd<<endl;
    //usleep(10000000);
    int res;
    char buf[255];
    memset(buf, 0, sizeof(buf));
    res = (int)read(fd, buf, sizeof(buf));
    if(res == -1){
        perror("recv()");
        exit(1);
    }
    printf("recv data: %s\n", buf);
    parseMsg(fd, buf);
    //int clientID = buf[2] - '0';
    //int destID = IDtoDestID[clientID];
    
    //if(destID == 0){
        std::thread h(threadRead, &fd);
        std::thread h2(threadWrite, &fd);
        
        
    //        memset(buf, 0, sizeof(buf));
    //        cout<<"Receive Client:"<<endl;
    //        res = (int)read(newfd, buf, sizeof(buf));
    //        if(res == -1){
    //            perror("recv()");
    //            exit(1);
    //        }
    //        cout<<buf<<endl;
    //        usleep(5000000);
        
        h.join();
        h2.join();
    //}
    
    //cout<<"mQueue Size():"<<mQueue.queueSize()<<endl;
    
    //free(vargp);
    return;
}

void IMServer::parseMsg(int newfd, const string &msg){
    int clientID;
    int destID = msg[0]-'0';
    clientID = msg[2]-'0';
    IDtoFD[clientID] = newfd;
    //IDtoDestID[clientID] = destID;
    
    cout<<"ID: "<<clientID<<", fd: "<<IDtoFD[clientID]<<endl;
    return;
}

void IMServer::threadRead(const int *varp){
    int sockfd = *(int*)varp;
    char buf1[255];
    while(true){
        memset(buf1, 0, sizeof(buf1));
        
        cout<<"Received client Messages: ";
        int res = (int)read(sockfd, buf1, sizeof(buf1));
        if(res == -1){
            perror("recv()");
            exit(1);
        }
        cout<<buf1<<endl;
        
        mQueue.insertItem(::string(buf1));
        cout<<"QueueItems: "<<endl;
        cout<<mQueue.queueSize()<<endl;
        usleep(1000000);
    }
    return;
}

void IMServer::threadWrite(const int *varp){
    int sockfd = *(int*)varp;
    int res;
    while(true){
        //cout<<"Server:Input message to send:"<<endl;
        //string msg = mQueue.removeItem();
        res = (int)write(sockfd, "Server messages", 18);
        //cout<<"Messeges Sent"<<endl;
        if(res == -1){
            perror("recv()");
            exit(1);
        }
        usleep(1000000);
    }
}
