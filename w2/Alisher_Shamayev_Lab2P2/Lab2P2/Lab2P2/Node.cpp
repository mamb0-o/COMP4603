//
//  Node.cpp
//  Lab2P2
//
//  Created by GUW06 on 2023-01-26.
//

#include "Node.hpp"
template <typename T>
Node<T>::Node() {
next = nullptr;
}

template <typename T>
Node<T>::Node(T element) {
this->element = element;
next = nullptr;
}
