//Question 1.
#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 5; 
    int arr[MAX_SIZE]; 
    int frontIndex, rearIndex;

public:
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty() {
        return frontIndex == -1 || frontIndex > rearIndex;
    }

    bool isFull() {
        return rearIndex == MAX_SIZE - 1;
    }

    // Enqueue operation (insert at rear)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (frontIndex == -1) 
            frontIndex = 0;
        arr[++rearIndex] = value;
        cout << value << " enqueued into queue." << endl;
    }

    // Dequeue operation (remove from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << arr[frontIndex++] << " dequeued from queue." << endl;
        if (frontIndex > rearIndex) 
            frontIndex = rearIndex = -1;
    }

    // Front operation (get front element)
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q; 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.display();

    return 0;
}



//--------------------------------------------------------------------------------



//Question 2.
#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear, size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == 5;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        rear = (rear + 1) % 5;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) return;
        front = (front + 1) % 5;
        size--;
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.dequeue();
    cout << "Front: " << cq.frontElement() << endl;
    return 0;
}



//--------------------------------------------------------------------------------



//Question 3.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; 
    Node* rear;  
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        if (front == nullptr)
            return true;
        return false;
    }

    // Enqueue operation (insert at rear)
    void enqueue(int value) {
        Node* newNode = new Node;
        if (newNode == nullptr) { 
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) { 
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into queue." << endl;
    }

    // Dequeue operation (remove from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;

        if (front == nullptr) 
            rear = nullptr;

        delete temp;
    }

    // Front operation (get front element)
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q; 
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.display();

    cout << "Is queue empty? ";
    if (q.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
