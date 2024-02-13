#include <iostream>
using namespace std;

class Uber {
public:
    virtual void uberService(string message) = 0;
};

class UberEats : public Uber {
public:
    void uberService(string message) {
        cout << message << endl;
    }
};

class User {
private:
    Uber* uberUser;

public:
    User(Uber* uberUser) : uberUser(uberUser) {}

    void orderFood(string cafe) {
        uberUser->uberService("placing order: " + cafe);
       
    }
};

int main() {
    UberEats uberEats1;
    User User(&uberEats1);
    User.orderFood("Wendy's");
    return 0;
}

