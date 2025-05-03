#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node;
        if (newNode == nullptr) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0'; 
        }
        Node* temp = top;
        char poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty() {
        if (top == nullptr)
            return true;
        return false;
    }
};

class ParenthesisChecker {
public:
    bool isBalanced(string expr) {
        Stack s; 
        for (int i = 0; i < expr.length(); i++) {
            if (expr[i] == '(') {
                s.push(expr[i]); 
            } else if (expr[i] == ')') {
                if (s.isEmpty()) {
                    return false;
                }
                s.pop();
            }
        }
        return s.isEmpty(); 
    }
};

int main() {
    ParenthesisChecker checker;
    int choice;
    string input;

    do {
        cout << "\n1. Check Balance\n2. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter string of parentheses: ";
            cin >> input;
            if (checker.isBalanced(input))
                cout << "Balanced" << endl;
            else
                cout << "Unbalanced" << endl;
        }
    } while (choice != 2);

    return 0;
}
