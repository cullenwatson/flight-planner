#pragma once

#include"List.h"

template<class T>
class Stack {
    List<T> list;
    int size;
public:
    Stack() : size(0) {}

    // remove element
    void pop() {
        list.pop_back();
        size--;
    }
    // add elemennt
    void push(const T& data) {
        list.push_back(data);
        size++;
    }
    // return top element
    T& top() {
        return list.back();
    }

    // predicate function
    bool isEmpty() {
        return list.isEmpty();
    }
    // get size
    int getSize() {
        return size;
    }
};
