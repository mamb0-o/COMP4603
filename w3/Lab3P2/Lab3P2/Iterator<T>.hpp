//
//  Iterator<T>.hpp
//  Lab3P2
//
//  Created by GUW06 on 2023-02-02.
//

#ifndef Iterator_T__hpp
#define Iterator_T__hpp

#include <stdio.h>
template<typename T>
class Iterator {
private:
    int current;
    vector<T> v;

public:
    Iterator(TreeNode<T>* p) {}

    Iterator<T> operator++() {
        ++current;
        return *this;
    }

    T operator*() {
        return v[current];
    }

    bool operator==(Iterator<T>& itr) {
        return current == itr.current;
    }

    bool operator!=(Iterator<T>& itr) {
        return current != itr.current;
    }
};
#endif /* Iterator_T__hpp */
