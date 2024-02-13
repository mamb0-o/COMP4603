//
//  Functor.cpp
//  Assignment9P1
//
//  Created by GUW06 on 2023-03-15.
//
#include <iostream>//>
#include <stdio.h>
using namespace std;

class Addition {
public:
  int operator()(int x, int y) const {
      return x+y;
  }
};

int main() {
    int x = 100, y = 788;
    auto add = [](int x, int y) { return x + y; };
      cout<< "Sum of " << x << "and " << y << "is "<<add(x,y)<<endl;
    return 0;

}
