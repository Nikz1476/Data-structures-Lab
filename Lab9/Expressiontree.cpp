#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() {
        root = nullptr;
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    Node* constructExpressionTree(string postfix) {
        stack<Node*> st;

        for (char ch : postfix) {
            if (!isOperator(ch)) {
                st.push(new Node(ch));  // Operand node
            } else {
                Node* newNode = new Node(ch);
                newNode->right = st.top(); st.pop();
                newNode->left = st.top(); st.pop();
                st.push(newNode);
            }
        }
        return st.top();  // Root of the expression tree
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void menu() {
        int choice;
        string postfix;
        do {
            cout << "\n1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter valid postfix expression: ";
                    cin >> postfix;
                    break;
                case 2:
                    root = constructExpressionTree(postfix);
                    cout << "Expression Tree Constructed.\n";
                    break;
                case 3:
                    cout << "Preorder Traversal: ";
                    preorder(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "Postorder Traversal: ";
                    postorder(root);
                    cout << endl;
                    break;
                case 6:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    ExpressionTree tree;
    tree.menu();
    return 0;
}
