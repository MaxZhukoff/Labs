#ifndef PRG_5_STACK_H
#define PRG_5_STACK_H

#include <string>
#include "stackException.h"

template<typename T>

class Stack {
public:
    Stack(const int &size) {
        maxSize = size;
        pointer = 0;
    }

    T top()const {
        if (pointer == 0) {
            throw StackException("Stack is empty!");
        }
        int index = pointer;
        index--;
        return stack[index];
    }

    bool isEmpty()const {
        return pointer == 0;
    }

    void push(const T &value) {
        if (pointer == maxSize) {
            throw StackException("Stack is overflow!");
        }
        stack[pointer] = value;
        pointer++;
    }
    void pop() {
        if (pointer == 0) {
            throw StackException("Stack is empty!");
        }
        stack[pointer] = 0;
        pointer--;
    }

    ~Stack() {
        delete[] stack;
    }

private:
    int pointer;
    int maxSize;
    T *stack = new T[maxSize]{};
};

#endif