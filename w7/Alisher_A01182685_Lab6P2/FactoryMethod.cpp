//
//  FactoryMethod.cpp
//  Assignment6P2
//
//  Created by GUW06 on 2023-02-27.
//

#include <iostream>
using namespace std;
class Car {
public:
    virtual string Manufacture();
};

class BMW : public Car {
public:
    string Manufacture() {
        return "BMW";
    }
};

class KIA : public Car {
public:
    string Manufacture() {
        return "KIA";
    }
};

class Porsche : public Car {
public:
    string Manufacture() {
        return "Porsche";
    }
};

class CarFactory {
public:
    Car* getCar(string brand) {
        if (brand == "Porsche") {
            return new Porsche();
        } else if (brand == "BMW") {
            return new BMW();
        } else if (brand == "KIA") {
            return new KIA();
        } else {
            return NULL;
        }
    }
};

