#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2; // Move up
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;
            
            if (largest == index)
                break;
            
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }
        cout << "Deleted Max: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        cout << "Heap elements: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    int choice, value;

    while (true) {
        cout << "\n1. Insert  2. Delete Max  3. Display  4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pq.insert(value);
                pq.display();
                break;
            case 2:
                pq.deleteMax();
                pq.display();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
