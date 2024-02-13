//
//  Adapter.cpp
//  P2
//
//  Created by GUW06 on 2023-03-08.
//


#include <iostream>
using namespace std;

class Football {
public:
  void kick() {
      cout <<"kick the ball"<< endl;
  }
};

class Basketball {
public:
    void shoot() {
        cout <<"shoot the ball"<< endl;
    }
};

class FootballAdapter : public Football {
private:
  Basketball *basketball;

public:
    FootballAdapter(Basketball *basketball){
        this->basketball=basketball;
    }
    void kick(){
        basketball->shoot();
    }
};

class BasketballAdapter : public Basketball {
private:
    Football *football;

public:
    BasketballAdapter(Football *football){
        this->football=football;
    }
    void shoot(){
        football->kick();
    }
};
