#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* getHead();  

public:
    LinkedList();  
    void insertAscending(int val);
    void display();
    void mergeLists(LinkedList& list1, LinkedList& list2);
};

LinkedList::LinkedList() {
    head = nullptr;
}

Node* LinkedList::getHead() {
    return head;
}

// Insert ascending
void LinkedList::insertAscending(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }
    if (head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < val) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Merge two sorted lists into the current list
void LinkedList::mergeLists(LinkedList& list1, LinkedList& list2) {
    Node* temp1 = list1.getHead();
    Node* temp2 = list2.getHead();

    if (temp1 == nullptr) {
        head = temp2;
        return;
    }
    if (temp2 == nullptr) {
        head = temp1;
        return;
    }

    if (temp1->data < temp2->data) {
        head = temp1;
        temp1 = temp1->next;
    } else {
        head = temp2;
        temp2 = temp2->next;
    }

    Node* current = head;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data < temp2->data) {
            current->next = temp1;
            temp1 = temp1->next;
        } else {
            current->next = temp2;
            temp2 = temp2->next;
        }
        current = current->next;
    }

    if (temp1 != nullptr) {
        current->next = temp1;
    } else {
        current->next = temp2;
    }
}
