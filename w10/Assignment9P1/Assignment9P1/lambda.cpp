//
//  lambda.cpp
//  Assignment9P1
//
//  Created by GUW06 on 2023-03-15.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  int x = 100, y = 788;
  auto lambdaFunc = [](int x, int y) { return x + y; };
    cout<< "Sum of " << x << " and " << y << " is "<<lambdaFunc(x,y)<<endl;
  return 0;
}
