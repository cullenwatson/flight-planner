#pragma once

#include<iostream>
using namespace std;

template<typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
        // constructor
        explicit Node(T val, Node* n = nullptr, Node* p = nullptr) :data(val), next(n), prev(p) {}
    };
    Node* head;
    Node* tail;
    Node* iter;
    Node* save;

public:
    // default constructor
    List() : head(nullptr), tail(nullptr), iter(nullptr), save(nullptr) {}
    // copy constructor (deep copy)
    List(const List& otherList) {
        head = tail = iter = nullptr;
        Node* temp = otherList.head;
        while (temp != nullptr) {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    // assignment operator (deep copy)
    List& operator=(const List& other) {
        if (this != &other) {
            Node* temp = head;
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            head = tail = iter = nullptr;
            Node* temp2 = other.head;
            while (temp2 != nullptr) {
                push_back(temp2->data);
                temp2 = temp2->next;
            }
        }
        return *this;
    }
    // destructor
    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // insert node at end of list
    void push_back(const T& nodeData) {
        // create new node
        auto newNode = new Node(nodeData);
        // if List is empty
        if (head == nullptr)
            // set List ptrs to start of List
            head = tail = iter = newNode;
        else {
            // insert node after tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }
    // insert node at front of list
    void push_front(const T& nodeData) {
        auto newNode = new Node(nodeData);
        // if list is empty
        if (head == nullptr)
            head = tail = iter = newNode;
        else {
            // point node to current head
            newNode->next = head;
            head->prev = newNode;
            // point head to new node
            head = newNode;
            // check if iter was at prev head
            if (iter == head->next) {
                iter = head;
            }
        }
    }
    // remove node at end of list
    void pop_back() {
        // check if list is empty
        if (head == nullptr)
            return;
        // check if size = 1
        if (head == tail) {
            delete head;
            head = tail = iter = nullptr;
        }
        // if size > 1
        else {
            Node* toDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete toDelete;
        }

    }
    // get size of list
    int getSize() {
        Node* current = head;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    // get value
    T& get(const T& d) {
        Node* current = head;
        int count = 0;
        while (current != nullptr)
        {
            if (current->data == d)
                return current->data;
            current = current->next;
        }
        throw "exception";
    }
    // returns data at given index (if valid)
    T& at(int index) {
        Node* traverse = head;
        for (int i = 0; i < index; i++) {
            traverse = traverse->next;
        }
        return traverse->data;
    }

    // adv iter
    void advIter() {
        iter = iter->next;
    }
    // reset iter
    void resetIter() {
        iter = head;
    }
    //  can get next
    bool canGetNext() {
        Node* temp = iter->next;
        if (temp != nullptr)
            return true;
        else
            return false;
    }
    // get next
    T& getNext() {
        Node* temp = iter->next;
        return temp->data;
    }
    // check if iter is null
    bool isIterNull() {
        if (iter == nullptr)
            return true;
        else
            return false;
    }
    // get iter data
    T& getIter()const {
        return iter->data;
    }
    // save iter
    void saveIter() {
        save = iter;
    }
    // restore iter
    void restoreIter() {
        iter = save;
    }
    // output list
    void output() {
        Node* traverse = head;
        while (traverse != nullptr) {
            cout << traverse->data << endl;
            traverse = traverse->next;
        }
        cout << endl;
    }
    // find
    bool find(const T& obj) {
        if (head == nullptr)
            return false;
        else {
            Node* traverse = head;
            while (traverse != nullptr) {
                if (traverse->data == obj) {
                    saveIter();
                    iter = traverse;
                    return true;
                }
                traverse = traverse->next;
            }
        }
        return false;
    }
    // check if list is empty
    bool isEmpty() {
        if (head != nullptr)
            return false;
        else
            return true;

    }
    // get back
    T& back() {
        if (tail != nullptr) {
            return tail->data;
        }
        else {
            throw "List is empty";
        }
    }
    // has prev
    bool hasPrev() {
        Node* temp = iter->prev;
        if (temp != nullptr)
            return true;
        return false;
    }
    T& getPrev() {
        Node* temp = iter->prev;
        return temp->data;
    }
};


