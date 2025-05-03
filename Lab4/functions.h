//Header file containing functions for inserting elements in ascending order, merging lists, and display list 
#include <iostream> 
 
using namespace std; 
 
class SLL{ 
    private: 
        struct Node{ 
            int data; 
            struct Node* next; 
        }; 
        struct Node* head; 
        struct Node* tail; 
        struct Node* get_head(){ 
            return head; 
        } 
    public: 
        SLL(); 
        void insert_ascending(int); 
        void merge_lists(SLL&, SLL&); 
        void display(); 
}list1, list2, list3; 
 
SLL::SLL(){ 
    head = NULL; 
    tail = NULL; 
} 
 
void SLL::insert_ascending(int value){ 
    struct Node* newnode = new struct Node; 
    newnode -> data = value; 
    if (head == NULL || head -> data >= value){ 
        newnode -> next = head; 

        head = newnode; 
        return; 
    } 
 
    struct Node* temp = head; 
    while (temp -> next && temp-> next -> data < value) { 
        temp = temp->next; 
    } 
 
    newnode -> next = temp->next; 
    temp->next = newnode; 
} 
 
void SLL::merge_lists(SLL& list1, SLL& list2) { 
    struct Node* temp1 = list1.head;   
    struct Node* temp2 = list2.head; 
 
    while (temp1 != NULL && temp2 != NULL){ 
        if (temp1 -> data > temp2 -> data){ 
            list3.insert_ascending(temp2 -> data);  
            temp2 = temp2 -> next; 
        }  
        else{ 
            list3.insert_ascending(temp1 -> data); 
            temp1 = temp1 -> next; 
        } 
    } 
 
    while (temp1 != NULL){ 
        list3.insert_ascending(temp1 -> data); 
        temp1 = temp1 -> next; 
    } 
 
    while (temp2 != NULL){ 
        list3.insert_ascending(temp2 -> data); 

        temp2 = temp2 -> next; 
    } 
} 
 
 
void SLL::display(){ 
    if (head == NULL){ 
        cout << "Empty list!" << endl; 
        return; 
    } 
    struct Node* temp = head; 
    while (temp -> next != NULL){ 
        cout << temp -> data << " -> "; 
        temp = temp -> next; 
    } 
    cout << temp -> data << endl; 
    return; 
} 
