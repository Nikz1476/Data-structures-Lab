#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class Node {
public:
    int key;
    Node* next;
    Node(int val) : key(val), next(nullptr) {}
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Key not found.\n";
            return;
        }

        if (prev == nullptr) {
            table[index] = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr;
        cout << "Deleted " << key << " from index " << index << endl;
    }

    void search(int key) {
        int index = hash(key);
        Node* curr = table[index];

        while (curr != nullptr) {
            if (curr->key == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            curr = curr->next;
        }

        cout << "Key not found.\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr != nullptr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
