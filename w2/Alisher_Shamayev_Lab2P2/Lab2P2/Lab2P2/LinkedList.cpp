//
//  LinkedList.cpp
//  Lab2P2
//
//  Created by GUW06 on 2023-01-26.
//

#include "LinkedList.hpp"
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    head = tail = nullptr;
    size = 0;
    for (auto x : list) addLast(x);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::addFirst(T element) {
    Node* newNode = new Node(element);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) tail = head;
    size++;
}

template <typename T>
void LinkedList<T>::addLast(T element) {
    Node* newNode = new Node(element);
    if (tail != nullptr) tail->next = newNode;
    tail = newNode;
    if (head == nullptr) head = tail;
    size++;
}

template <typename T>
T LinkedList<T>::getFirst() const {
    if (head == nullptr) throw std::out_of_range("List is empty");
    return head->data;
}

template <typename T>
T LinkedList<T>::getLast() const {
    if (tail == nullptr) throw std::out_of_range("List is empty");
    return tail->data;
}

template <typename T>
T LinkedList<T>::removeFirst() {
    if (head == nullptr) throw std::out_of_range("List is empty");
    T data = head->data;
    Node* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete temp;
    size--;
    return data;
}

template <typename T>
T LinkedList<T>::removeLast() {
    if (tail == nullptr) throw std::out_of_range("List is empty");
    T data = tail->data;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
    return data;
}

template <typename T>
void LinkedList<T>::add(T element) {
    addLast(element);
}

template <typename T>
void LinkedList<T>::add(int index, T element) {
    if (index == 0) {
    addFirst(element);
    return;
    }
    if (index == size) {
    addLast(element);
    return;
    }
    if (index < 0 || index > size) throw std::out_of_range("Index out of range");
    Node* current = head;
    for (int i = 0; i < index - 1; i++) current = current->next;
    Node* newNode = new Node(element);
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
bool LinkedList<T>::contains(T element) const {
    Node* current = head;
    while (current != nullptr) {
    if (current->data == element) return true;
    current = current->next;
    }
    return false;
}

template <typename T>
T LinkedList<T>::get(int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    Node* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    return current->data;
}

template <typename T>
int LinkedList<T>::indexOf(T element) const {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
    if (current->data == element) return index;
    current = current->next;
    index++;
    }
    return -1;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int LinkedList<T>::lastIndexOf(T element) const {
    Node* current = head;
    int index = 0, lastIndex = -1;
    while (current != nullptr) {
    if (current->data == element) lastIndex = index;
    }
}

template <typename T>
void LinkedList<T>::remove( T element) {
    delete element;
}

template <typename T>
int LinkedList<T>::getSize() const{
    Node* current=head;
    int count=0;
    while(current!=nullptr){
        count++;
    }
}

template <typename T>
T LinkedList<T>::removeAt(int index)  {
    if (index < 0 || index >= size)
        printf("Index out of range");
    else if (index == 0)
    return removeFirst();
    else if (index == size - 1)
    return removeLast();
    else {
    Node* previous = head;
    for (int i = 1; i < index; i++)
    {
    previous = previous->next;
    }
    Node* current = previous->next;
    previous->next = current->next;
    size--;
    T element = current->element;
    delete current;
        return element;
    }
}

template <typename T>
T LinkedList<T>::set(int index, T element) {
    if (index == 0) {
        T old= getFirst();
        addFirst(element);
        return old;
    }
    if (index == size) {
        T old=getLast();
        addLast(element);
        return old;
    }
    if (index < 0 || index > size) throw std::out_of_range("Index out of range");
        Node* current = head;
        for (int i = 0; i < index - 1; i++) current = current->next;
        T old=current->next;
        Node* newNode = new Node(element);
        newNode->next = current->next;
        current->next = newNode;
        size++;
        return old;
}


