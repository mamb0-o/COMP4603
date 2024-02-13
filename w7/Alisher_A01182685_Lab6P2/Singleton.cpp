//
//  Singleton.cpp
//  Assignment6P2
//
//  Created by GUW06 on 2023-02-27.
//

#include <iostream>;
using namespace  std;
class Playstation5 {
public:
    static Playstation5& getConsole() {
        return console;
    }

    Playstation5(Playstation5 const&) = delete;
    Playstation5(Playstation5&&) = delete;

    Playstation5& operator=(Playstation5 const&) = delete;
    Playstation5& operator=(Playstation5 &&) = delete;

private:
    Playstation5() {}
    static Playstation5 console;
};
