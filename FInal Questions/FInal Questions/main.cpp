#include <iostream>
using namespace std;

// base class Football
class Football {
public:
    virtual void fact() {
        cout << "Sport Football" << endl;
    }
};

// deriving class from Football
class Soccer : public Football {
public:
    void fact() override {
        cout << "Soccer believes to be coming from England but also named Football " << endl;
    }
};


// League class
class League {
public:
    virtual void play() {
        cout << "Game length is 90 minutes" << endl;
    }
};

// class extends from both Football and League
class europeFootball : public Football, public League {
public:
    void play() override {
        cout << "Have lots of championships and 5 main top oned around the whole world!" << endl;
    }
};

int main() {
    Football* game = new europeFootball();  // we create europeFootball object
    game->fact();  //calling its function


    League* champ = dynamic_cast<League*>(game);// crooss cast from Football to a league
       if (champ != nullptr) {
           champ->play();
       }
    return 0;
}
