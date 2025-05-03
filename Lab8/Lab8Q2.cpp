#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;

        Node(char value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root; 

public:
    BinaryTree() {
        root = nullptr;
    }

    // Recursive insert function (calls private helper)
    void insert(char value) {
        root = insertRecursive(root, value);
    }

    // Recursive search function (calls private helper)
    bool search(char value) {
        return searchRecursive(root, value);
    }

    // Recursive Preorder Traversal
    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    // Recursive Inorder Traversal
    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    // Recursive Postorder Traversal
    void displayPostorder() {
        postorder(root);
        cout << endl;
    }

private:
    Node* insertRecursive(Node* node, char value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    // Helper function to recursively search for a node
    bool searchRecursive(Node* node, char value) {
        if (node == nullptr) return false;
        if (node->data == value) return true; 
        if (value < node->data) return searchRecursive(node->left, value);
        return searchRecursive(node->right, value);
    }

    // Helper function for Preorder Traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for Inorder Traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for Postorder Traversal
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

// Main Function - Menu Driven Program
int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.displayPreorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.displayInorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.displayPostorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Character found in the tree!\n";
                else
                    cout << "Character not found.\n";
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
