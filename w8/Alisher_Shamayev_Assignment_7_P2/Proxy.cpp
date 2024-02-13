//
//  Server.cpp
//  P2
//
//  Created by GUW06 on 2023-03-08.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Server {
public:
    virtual void getServer(string request) = 0;
};


class RealServer : public Server {
public:
    void getServer(string request) override {
        cout << "Handling request: " <<  " (using the Real Server)" << endl;
    }
};


class ProxyServer : public Server {
private:
    RealServer* realServer;
public:
    ProxyServer() {
        realServer = new RealServer();
    }

    void getServer(string request) override {
        if (request.length() <= 5) {
            cout << "Handling request: " << " (using the Proxy Server)" << endl;
        }
        else {
            realServer->getServer(request);
        }
    }
};
