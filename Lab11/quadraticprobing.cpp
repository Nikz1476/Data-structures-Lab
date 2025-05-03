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
        int i = 0;

        while (i < TABLE_SIZE) {
            int probe = (index + i * i) % TABLE_SIZE;
            if (table[probe] == EMPTY || table[probe] == DELETED) {
                table[probe] = key;
                cout << "Inserted " << key << " at index " << probe << endl;
                return;
            } else if (table[probe] == key) {
                cout << "Duplicate key. Insertion not allowed.\n";
                return;
            }
            i++;
        }
        cout << "Hash table is full. Could not insert.\n";
    }

    void remove(int key) {
        int index = hash(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int probe = (index + i * i) % TABLE_SIZE;
            if (table[probe] == EMPTY) {
                break;
            } else if (table[probe] == key) {
                table[probe] = DELETED;
                cout << "Deleted " << key << " from index " << probe << endl;
                return;
            }
            i++;
        }
        cout << "Key not found.\n";
    }

    void search(int key) {
        int index = hash(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int probe = (index + i * i) % TABLE_SIZE;
            if (table[probe] == EMPTY) {
                break;
            } else if (table[probe] == key) {
                cout << "Found " << key << " at index " << probe << endl;
                return;
            }
            i++;
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
