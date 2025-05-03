#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; 

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        if (top == nullptr)
            return true;
        return false;
    }

    void push(int value) {
        Node* newNode = new Node;
        if (newNode == nullptr) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
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

    cout << "Is stack empty? ";
    if (s.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
