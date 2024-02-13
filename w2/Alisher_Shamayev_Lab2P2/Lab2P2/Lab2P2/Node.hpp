//
//  Node.hpp
//  Lab2P2
//
//  Created by GUW06 on 2023-01-26.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
template <typename T>
class Node {
public:
T element;
Node<T>* next;
Node();
Node(T element);
};
#endif /* Node_hpp */
