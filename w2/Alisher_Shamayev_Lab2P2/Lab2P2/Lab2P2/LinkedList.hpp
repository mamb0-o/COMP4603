//
//  LinkedList.hpp
//  Lab2P2
//
//  Created by GUW06 on 2023-01-26.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();
    void addFirst(T element);
    void addLast(T element);
    T getFirst() const;
    T getLast() const;
    T removeFirst();
    T removeLast();
    void add(T element);
    void add(int index, T element);
    void clear();
    bool contains(T element) const;
    T get(int index) const;
    int indexOf(T element) const;
    bool isEmpty() const;
    int lastIndexOf(T element) const;
    void remove(T element);
    int getSize() const;
    T removeAt(int index);
    T set(int index, T element);
    class Iterator;
    Iterator begin() const{return Iterator(head);}
    Iterator end() const{return Iterator(nullptr);}
};



#endif /* LinkedList_hpp */
