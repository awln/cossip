/* 
 * cp_server.h
 * 
 * Header file for gossip server establishment
*/

#ifndef _CP_SERVER_H_ // if not defined, define
#define _CP_SERVER_H_

#include <sys/types.h>
#include <mutex>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>



class Cp_Server{ // node factory that listens for client connections and creation of node receivers
    Cp_server(){

    }

    start(){
        while(1){
            //accept
        }
    }
};


#endif