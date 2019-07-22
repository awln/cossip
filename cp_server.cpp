#include "cp_server.h"
#include <iostream>
#include <sys/types.h>
// #include <mutex>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

cp_server::cp_server(){

}

void cp_server::start(){
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