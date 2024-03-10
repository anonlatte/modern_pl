#ifndef LAB_9
#define LAB_9

#include <cstdio>

template<class T>
class TStack {
protected:
    int numItem;
    T *item;
public:
    explicit TStack(size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }

    ~TStack() {
        delete[] item;
    }

    void push(T t);

    T pop();

    T peek();

    bool isEmpty() {
        return numItem <= 0;
    }
};

template<class T>
void TStack<T>::push(T t) {
    item[numItem++] = t;
}

template<class T>
T TStack<T>::pop() {
    return item[--numItem];
}

template<class T>
T TStack<T>::peek() {
    return item[numItem - 1];
}

#endif