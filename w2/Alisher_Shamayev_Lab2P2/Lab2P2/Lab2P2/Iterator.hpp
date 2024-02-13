#include <stdio.h>
template <typename T>
class Iterator {
    private:
    struct Node{
        Node<T>* current;
    };
    public:
        Iterator(Node<T>* p) : current(p) {}; // constructor
        Iterator<T> operator++() {
            current = current->next;
            return *this;
        }
        T& operator*() {
            return current->data;
        }
        bool operator==(Iterator<T> &itr) {
            return current == itr.current;
        }
        bool operator!=(Iterator<T> &itr) {
            return current != itr.current;
        }
};
