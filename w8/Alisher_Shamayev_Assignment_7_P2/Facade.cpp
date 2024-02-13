//
//  Facade.cpp
//  P2
//
//  Created by GUW06 on 2023-03-08.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Lights {
public:
    void turnOn() {
        cout << "Lights on"<<endl;;
    }

    void turnOff() {
        cout << "Lights off"<<endl;;
    }
};

// Screen class
class Screen {
public:
    void turnOn() {
        cout << "Screen on"<<endl;;
    }

    void turnOff() {
        cout << "Screen off"<<endl;;
    }
};

// Cinema Facade class
class CinemaFacade {
private:
    Lights *lights;
    Screen *screen;

public:
    CinemaFacade(Lights *lights, Screen *screen){
        this->screen=screen;
        this->lights=lights;
    }
    
    void movieOn() {
        lights->turnOff();
        screen->turnOn();
    }

    void movieOff() {
        lights->turnOn();
        screen->turnOff();
    }
};
