#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = val;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    // Top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Check if empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check if full
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack s(size);

    // Pushing elements
    for (int i = 0; i < size; i++) {
        int val;
        cout << "Enter value to push: ";
        cin >> val;
        s.push(val);
    }

    s.display();

    // Pop one element
    cout << "Popping top element...\n";
    s.pop();

    s.display();

    cout << "Top element is: " << s.top() << endl;

    return 0;
}

