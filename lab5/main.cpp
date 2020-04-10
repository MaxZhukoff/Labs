#include <iostream>
#include <string>
#include "degree.h"
#include "stack.h"
using namespace std;


int main() {
    double number;
    int power;
    cout << "Enter the number and degree" << endl;
    cin >> number >> power;
    cout << degree(number, power) << endl;

////////////////////////////////////////////////////////////////////
    int size;
    cout << "Enter the size of the stack" << endl;
    cin >> size;
    auto* stack = new Stack<int>(size);

    try {
        cout << "On top of the stack is ";
        cout << stack->top() << endl;
    }
    catch (StackException &ex) {
        cout << "NaN" << endl;
        ex.what();
    }

    try {
        cout << "Enter the number to push" << endl;
        int num;
        cin >> num;
         stack->push(num);
    }
    catch (StackException &ex){
        ex.what();
    }

    try {
    cout << "On top of the stack is ";
    cout << stack->top() << endl;
    }
    catch (StackException &ex) {
        cout << "NaN" << endl;
        ex.what();
    }

    try {
        stack->pop();
    }
    catch (StackException &ex){
        ex.what();
    }

    try {
        stack->pop();
    }
    catch (StackException &ex){
        ex.what();
    }


    delete stack;
    return 0;
}
