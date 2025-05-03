#include <iostream>
#include <vector>
#include <list>
using namespace std;

class graph {
private:
    vector<list<int>> adjlist;
    int vertices;

public:
    graph(int n) {
        vertices = n;
        adjlist.resize(vertices);
    }

    void insert(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            cout << "Invalid edge.\n";
            return;
        }
        adjlist[u].push_back(v);
        cout << "Edge inserted from: " << u << " -> " << v << endl;
    }

    void delet(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            cout << "Invalid edge.\n";
            return;
        }
        adjlist[u].remove(v);
        cout << "Edge deleted from: " << u << " -> " << v << endl;
    }

    void search(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            cout << "Invalid edge.\n";
            return;
        }
        for (int neighbor : adjlist[u]) {
            if (neighbor == v) {
                cout << "Edge found from " << u << " -> " << v << endl;
                return;
            }
        }
        cout << "Edge not found from " << u << " -> " << v << endl;
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int k : adjlist[i]) {
                cout << k << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, ch, u, v;
    cout << "Enter number of vertices: ";
    cin >> n;
    graph g(n);

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter the choice (1-5): ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter edge u and v to insert: ";
            cin >> u >> v;
            g.insert(u, v);
            break;
        case 2:
            cout << "Enter edge u and v to delete: ";
            cin >> u >> v;
            g.delet(u, v);
            break;
        case 3:
            cout << "Enter edge u and v to search: ";
            cin >> u >> v;
            g.search(u, v);
            break;
        case 4:
            cout << "Adjacency List:\n";
            g.display();
            break;
        case 5:
            cout << "Thank you, exiting.\n";
            break;
        default:
            cout << "Invalid choice, please enter between 1–5.\n";
            break;
        }
    } while (ch != 5);

    return 0;
}

