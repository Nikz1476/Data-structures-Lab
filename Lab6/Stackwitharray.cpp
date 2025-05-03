#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 5; 
    int arr[MAX_SIZE]; 
    int top;

public:
    Stack() {
        top = -1; 
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s; 

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;

    return 0;
}
