#include <iostream>
#include <cstdlib>
using namespace std;

class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
    };

    Node* head; 
public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertBeginning(int data) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;

        if (head == NULL) {
            newnode->next = newnode; 
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }
    }

    // Insert at End
    void insertEnd(int data) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;

        if (head == NULL) {
            newnode->next = newnode; 
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head; 
        }
    }

    // Insert at Position
    void insertPosition(int data, int pos) {
        if (head == NULL || pos == 1) {
            insertBeginning(data);
            return;
        }

        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = data;

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (head->next == head) { 
            free(head);
            head = NULL;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            free(temp);
        }
    }

    // Delete from End
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        while (temp->next->next != head) {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = head;
    }

    // Delete at Position
    void deletePosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head) { 
            cout << "Position out of range!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
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

    // Display List
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, data, position;

    do {
        cout << "\nCircular Linked List Operations:\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert at Position\n4. Delete Beginning\n";
        cout << "5. Delete End\n6. Delete at Position\n7. Display\n8. Search\n9. Exit";
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
                list.display();
                break;
            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                list.search(data);
                break;
            case 9:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
