//
//  Prototype.cpp
//  Assignment6P2
//
//  Created by GUW06 on 2023-02-27.
//

#include <iostream>;

using namespace std;

class Console {
public:
    virtual Console* clone();
    virtual std::string getName();
};

class Playstation : public Console {
public:
    Console* clone() override {
        return new Playstation(*this);
    }
    string getName() override {
        return "Playstation";
    }
};

class GameBoy : public Console {
public:
    Console* clone() override {
        return new GameBoy(*this);
    }
    string getName() override {
        return "GameBoy";
    }
};

int main() {
    Playstation* ps = new Playstation();
    GameBoy* gb = new GameBoy();

    Console* psClone = ps->clone();
    Console* gbClone = gb->clone();
    cout << "This is clone of: " << psClone->getName() << endl;
    cout << "This is clone of: " << gbClone->getName() << endl;
    
    return 0;
}

