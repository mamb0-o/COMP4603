//
//  observer.cpp
//  Lab2
//
//  Created by GUW06 on 2023-03-14.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Query : public Observer {
public:
    void update() override {
    }
};

class Database {
private:
    vector<Observer*> observers;

public:
    void runQuery(Observer* observer) {
        observer->update();
    }

    void deleteQuery(Observer* observer) {
        observer->update();
    }
};
