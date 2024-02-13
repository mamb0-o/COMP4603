//
//  Queue.cpp
//  Lab3P1
//
//  Created by GUW06 on 2023-01-26.
//

#include "Queue.hpp"
#include <iostream>

template <typename T>
void Queue<T>::enqueue(T element) {
    queue.push_back(element);
}

template<typename T>
T Queue<T>::dequeue() {
    if (queue.empty()) {
        throw std::out_of_range("Queue is empty");
    }
    T element = queue.front();
    queue.pop_front();
    return element;
}

template<typename T>
int Queue<T>::getSize()const{
    return queue.size();
}
