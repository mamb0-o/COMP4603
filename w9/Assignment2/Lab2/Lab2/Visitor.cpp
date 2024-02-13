//
//  Visitor.cpp
//  Lab2
//
//  Created by GUW06 on 2023-03-14.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
class Taxi;

class Visitor {
public:
    virtual void visit(Taxi& taxi) = 0;
};

class Taxi {
public:
    void accept(Visitor& visitor) {
        visitor.visit(*this);
    }
};


class Client : public Visitor {
public:
    void visit(Taxi& taxi) override {
        cout << "The Ride starts." << endl;
    }
};

class Driver : public Visitor {
public:
    void visit(Taxi& taxi) override {
        cout << "The Ride is completed!" << endl;
    }
};


