//
//  Queue.hpp
//  Lab3P1
//
//  Created by GUW06 on 2023-01-26.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
#include <list>

template <typename T>
class Queue {
    private:
        std::list<T> queue;
    public:
    void enqueue(T element) ;
    T dequeue();
    int getSize() const;
};
#endif /* Queue_hpp */
