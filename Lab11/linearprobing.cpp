#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    void insert(int key) {
        int index = hash(key);
        int start = index;
        while (table[index] != EMPTY && table[index] != DELETED) {
            if (table[index] == key) {
                cout << "Duplicate key. Insertion not allowed.\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                cout << "Hash table is full.\n";
                return;
            }
        }
        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hash(key);
        int start = index;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        cout << "Key not found.\n";
    }

    void search(int key) {
        int index = hash(key);
        int start = index;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Found " << key << " at index " << index << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        cout << "Key not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (table[i] == EMPTY)
                cout << "EMPTY";
            else if (table[i] == DELETED)
                cout << "DELETED";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
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
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
