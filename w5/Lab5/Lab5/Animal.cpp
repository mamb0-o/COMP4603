//
//  Animal.cpp
//  Lab5
//
//  Created by GUW06 on 2023-02-10.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void breed() {
        cout << "The number of species in just the animal kingdom is estimated to range from 1 to 2 million, however, some sources place the number as high as 50 million." << endl;
    }

    virtual void price() = 0;
};

class Cat : public Animal {
public:
    void breed() override {
        cout << "There between 40 to 70 different cat breeds" << endl;
    }

    void price() override {
        cout << "Usually you can buy a cat for average price about 1000$" << endl;
    }
};

class Dog : public Animal {
public:
    void breed() override {
        cout << "In the world officially there is 360 different dog breeds!" << endl;
    }

    void price() override {
        cout << "Average Price for a dog will be equal to around 3500$" << endl;
    }
};

class Poodle : public Dog {
public:
    void breed() override {
        cout << "Poodle is a dog breed" << std::endl;
    }
    
    void price() override {
        cout << "A poodle price might vary between 1500-2500 which is lower than average!" << endl;
    }
};
