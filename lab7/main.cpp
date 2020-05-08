#include "CircularBuffer.h"

using namespace std;

int main() {
    CircularBuffer<int> Buffer(10);
    Buffer.push_top(100);
    Buffer.push_back(25);
    Buffer.push_top(33);
    Buffer.push_back(4);
    Buffer.push_back(55);
    Buffer.push_back(6);
    Buffer.push_top(7);
    Buffer.push_back(8);
    Buffer.push_top(9);
    Buffer.push_top(10);
	Buffer[0] = 0;
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Delete 9" << endl;
    Buffer.erase(find(Buffer.begin(), Buffer.end(), 9));
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Delete 33" << endl;
    Buffer.erase(find(Buffer.begin(), Buffer.end(), 33));
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Insert 11110" << endl;
    Buffer.insert(find(Buffer.begin(), Buffer.end(), Buffer[5]), 1111);
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Capacity = 5" << endl;
    Buffer.resize(5);
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Push top 228" << endl;
    Buffer.push_top(228);
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Pop top" << endl;
    Buffer.pop_top();
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Push back 1337" << endl;
    Buffer.push_back(1337);
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    cout << "Pop back" << endl;
    Buffer.pop_back();
    for (int i : Buffer) {
        cout << i << " ";
    }
    cout << endl << endl;
    return 0;
}