/* 
 * cp_server.h
 * 
 * Header file for gossip server establishment
*/

#ifndef _CP_SERVER_H_ // if not defined, define
#define _CP_SERVER_H_

#include <iostream>
#include <sys/types.h>
#include <mutex>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

class cp_server{ // node factory that listens for client connections and creation of node receivers
    cp_server(){
        
    }

    void start(){
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        int option = 1;
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&option, sizeof(option));

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(8000);
        bind(server_fd, (struct sockaddr*) &addr, sizeof(addr));

        //listen
        listen(server_fd, 10);
        
        socklen_t addrlen = (socklen_t) sizeof(addr);
        getsockname(server_fd, (struct sockaddr*)&addr, &addrlen);
        
        while(1){
            //accept
            cout << "WAITING FOR REQUEST" << endl;
            int connection = accept(server_fd, (struct sockaddr*)&addr, &addrlen);
            //handle request
        }
    }
};


#endif