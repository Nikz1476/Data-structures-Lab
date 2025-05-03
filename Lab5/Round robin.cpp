#include <iostream>
using namespace std;

class RoundRobinScheduler {
private:
    struct Process {
        int time;
        Process* next;
    };

    Process* tail; 
    int time_quantum;

public:
    RoundRobinScheduler(int tq) {
        tail = NULL;
        time_quantum = tq;
    }

    void insertProcess(int exec_time) {
        Process* newProcess = new Process;
        newProcess->time = exec_time;

        if (tail == NULL) { // If the queue is empty
            newProcess->next = newProcess; 
            tail = newProcess;
        } else {
            newProcess->next = tail->next; // Insert at the end
            tail->next = newProcess;
            tail = newProcess;
        }
        cout << "Process with time " << exec_time << " inserted.\n";
    }

    // Function to execute the round-robin scheduling
    void executeProcess() {
        if (tail == NULL) {
            cout << "No processes in the queue.\n";
            return;
        }

        Process* head = tail->next; 
        cout << "Executing process with time: " << head->time << endl;

        if (head->time <= time_quantum) {
            cout << "Process completed.\n";
            if (head == tail) { 
                delete head;
                tail = NULL;
            } else {
                tail->next = head->next; // Remove head from list
                delete head;
            }
        } else {
            head->time -= time_quantum;
            cout << "Remaining time after execution: " << head->time << endl;
            tail = head; // Move head to end
        }
    }

    //display
    void displayQueue() {
        if (tail == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        Process* temp = tail->next;
        cout << "Current Queue: ";
        do {
            cout << temp->time << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(Back to start)\n";
    }
};

int main() {
    int time_quantum;
    cout << "Enter the fixed time quantum: ";
    cin >> time_quantum;

    RoundRobinScheduler scheduler(time_quantum);

    int choice, exec_time;
    while (true) {
        cout << "\n1. Insert Process\n2. Execute\n3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process execution time: ";
                cin >> exec_time;
                scheduler.insertProcess(exec_time);
                break;
            case 2:
                scheduler.executeProcess();
                break;
            case 3:
                scheduler.displayQueue();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
