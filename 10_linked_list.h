#ifndef LINKED_LIST
#define LINKED_LIST

#include <cstdio>

template<class T>
struct Node {
    int key{};
    T data;
    Node *next = nullptr;
};

template<class T>
struct LinkedList {
    Node<T> *start = nullptr;
    Node<T> *end = nullptr;

public:
    void add(int key, T data);

    void first(int key, T data);

    Node<T> *find(int key);

    Node<T> *findPrev(int key);

    Node<T> *remove(int key);
};

//---------------------------------------------------
template<class T>
void LinkedList<T>::first(int key, T data) {
    start = new Node<T>;
    start->key = key;
    start->data = data;
    start->next = nullptr;
    end = start;
}

template<class T>
void LinkedList<T>::add(int key, T data) {
    if (start == nullptr) {
        first(key, data);
        return;
    }

    auto *n = new Node<T>;
    n->key = key;
    n->data = data;

    if (&start == &end) {
        start->next = n;
        n->next = end;
    } else {
        end->next = n;
        end = n;
    }
}

template<class T>
Node<T> *LinkedList<T>::findPrev(int key) {
    Node<T> *prev = start;
    Node<T> *cur = start;
    do {
        if (cur->key == key) {
            return prev;
        }
        prev = cur;
        cur = cur->next;
    } while (cur->next != nullptr);
    return nullptr;
}

template<class T>
Node<T> *LinkedList<T>::find(int key) {
    Node<T> *cur = start;
    while (cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

template<class T>
Node<T> *LinkedList<T>::remove(int key) {
    Node<T> *prev = findPrev(key);
    Node<T> *cur = find(key);
    if (cur == start) {
        start = nullptr;
        return cur;
    }
    prev->next = cur->next;
    return cur;
}

#endif