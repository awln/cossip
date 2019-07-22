/* 
 * cp_server.h
 * 
 * Header file for gossip factory server establishment
*/

#ifndef _CP_SERVER_H_ // if not defined, define
#define _CP_SERVER_H_

using namespace std;

class cp_server{ // node factory that listens for client connections and creation of node receivers
public:
    cp_server();
    ~cp_server();

    void start();
};


#endif