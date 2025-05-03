#include <iostream>
#include <cstdlib>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at Beginning
    void insertBeginning(int data) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = head;

        if (head == NULL) {  // If list is empty, update tail 
            tail = newnode;
        } else {
            head->prev = newnode;
        }
        head = newnode;
    }

    // Insert at End
    void insertEnd(int data) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = tail;

        if (tail == NULL) {  // If list is empty, update head too
            head = newnode;
        } else {
            tail->next = newnode;
        }
        tail = newnode;
    }

    // Insert at Position
    void insertPosition(int data, int pos) {
        if (pos == 1) {
            insertBeginning(data);
            return;
        }

        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;

        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            free(newnode);
            return;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        } else {
            tail = newnode;
        }

        temp->next = newnode;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        free(temp);
    }

    // Delete from End
    void deleteEnd() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }

        free(temp);
    }

    // Delete at Position
    void deletePosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        free(temp);
    }

    // Search
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found!" << endl;
    }

    // Display 
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

    

int main() {
    DoublyLinkedList list;
    int choice, data, position;

    do {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert at Position\n4. Delete Beginning\n";
        cout << "5. Delete End\n6. Delete at Position\n7. Search\n8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                list.insertBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertEnd(data);
                break;
            case 3:
                cout << "Enter data and position to insert: ";
                cin >> data >> position;
                list.insertPosition(data, position);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deletePosition(position);
                break;
            case 7:
                cout << "Enter data to search: ";
                cin >> data;
                list.search(data);
                break;
            case 8:
                list.display();
                break;;
            case 9:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    } while (choice != 9);
    return 0;
}
