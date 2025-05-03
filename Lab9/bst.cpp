#include <iostream>
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

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, char value) {
        if (node == nullptr) return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    void insert(char value) {
        root = insert(root, value);
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

    bool search(Node* node, char key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        return (key < node->data) ? search(node->left, key) : search(node->right, key);
    }

    void menu() {
        int choice;
        char value;
        do {
            cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter character to insert: ";
                    cin >> value;
                    insert(value);
                    break;
                case 2:
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl;
                    break;
                case 3:
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                    break;
                case 4:
                    cout << "Postorder: ";
                    postorder(root);
                    cout << endl;
                    break;
                case 5:
                    cout << "Enter character to search: ";
                    cin >> value;
                    if (search(root, value))
                        cout << "Found\n";
                    else
                        cout << "Not Found\n";
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
    BST tree;
    tree.menu();
    return 0;
}
