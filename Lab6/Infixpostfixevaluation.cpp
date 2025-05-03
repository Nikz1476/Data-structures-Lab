#include <iostream>
#include <cctype>
using namespace std;

class Stack {
private:
    class Node {
    public:
        void* data; 
        Node* next;
        Node(void* value) : data(value), next(nullptr) {} 
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(char value) {
        void* newData = new char(value); 
        Node* newNode = new Node(newData);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (!top) return '\0';
        char value = *(char*)top->data;
        Node* temp = top;
        top = top->next;
        delete (char*)temp->data;  
        delete temp;
        return value;
    }

    char peek() {
        return (top == nullptr) ? '\0' : *(char*)top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

class InfixToPostfix {
public:
    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    static bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }

    static string convert(string infix) {
        Stack s;
        string postfix = "";
        
        for (char ch : infix) {
            if (isalnum(ch)) {
                postfix += ch;
            } else if (ch == '(') {
                s.push(ch);
            } else if (ch == ')') {
                while (!s.isEmpty() && s.peek() != '(') {
                    postfix += s.pop();
                }
                s.pop();  // Remove '('
            } else if (isOperator(ch)) {
                while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                    postfix += s.pop();
                }
                s.push(ch);
            }
        }

        while (!s.isEmpty()) {
            postfix += s.pop();
        }

        return postfix;
    }
};

class PostfixEvaluator {
private:
    class Stack {
    private:
        class Node {
        public:
            void* data;
            Node* next;
            Node(void* value) : data(value), next(nullptr) {}
        };
        Node* top;

    public:
        Stack() : top(nullptr) {}

        void push(int value) {
            void* newData = new int(value);
            Node* newNode = new Node(newData);
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (!top) return 0;
            int value = *(int*)top->data;
            Node* temp = top;
            top = top->next;
            delete (int*)temp->data;
            delete temp;
            return value;
        }

        bool isEmpty() {
            return top == nullptr;
        }
    };

public:
    static int evaluate(string postfix) {
        Stack s;
        for (char ch : postfix) {
            if (isdigit(ch)) {
                s.push(ch - '0');
            } else {
                int val2 = s.pop();
                int val1 = s.pop();
                switch (ch) {
                    case '+': s.push(val1 + val2); break;
                    case '-': s.push(val1 - val2); break;
                    case '*': s.push(val1 * val2); break;
                    case '/': s.push(val1 / val2); break;
                    case '^': s.push(pow(val1, val2)); break;
                }
            }
        }
        return s.pop();
    }
};

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = InfixToPostfix::convert(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = PostfixEvaluator::evaluate(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
