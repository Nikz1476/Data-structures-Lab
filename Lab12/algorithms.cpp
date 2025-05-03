#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int MAX = 100;
int adjMatrix[MAX][MAX];
int edgeList[MAX * MAX][3]; // u, v, w
int V, E;

void addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
    edgeList[E][0] = u;
    edgeList[E][1] = v;
    edgeList[E][2] = w;
    E++;
}

void prims() {
    bool visited[MAX] = {false};
    int key[MAX];
    int parent[MAX];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && !visited[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0;
    cout << "Edges in MST (Prim's):\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << endl;
        cost += adjMatrix[i][parent[i]];
    }
    cout << "Total cost: " << cost << endl;
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal() {
    // Manual bubble sort by edge weight
    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {
            if (edgeList[i][2] > edgeList[j][2]) {
                int tmp0 = edgeList[i][0], tmp1 = edgeList[i][1], tmp2 = edgeList[i][2];
                edgeList[i][0] = edgeList[j][0];
                edgeList[i][1] = edgeList[j][1];
                edgeList[i][2] = edgeList[j][2];
                edgeList[j][0] = tmp0;
                edgeList[j][1] = tmp1;
                edgeList[j][2] = tmp2;
            }
        }
    }

    int parent[MAX], rank[MAX] = {0};
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;
    cout << "Edges in MST (Kruskal's):\n";
    for (int i = 0; i < E; i++) {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        int w = edgeList[i][2];
        int set_u = find(parent, u);
        int set_v = find(parent, v);
        if (set_u != set_v) {
            cout << u << " - " << v << " : " << w << endl;
            cost += w;
            unionSet(parent, rank, set_u, set_v);
        }
    }
    cout << "Total cost: " << cost << endl;
}

void dijkstra(int src) {
    int dist[MAX];
    bool visited[MAX] = {false};
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "To " << i << " : " << dist[i] << endl;
}

int main() {
    V = 5; E = 0;

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    int choice;
    do {
        cout << "\nMenu:\n1. Prim's Algorithm\n2. Kruskal's Algorithm\n3. Dijkstra's Algorithm\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: prims(); break;
            case 2: kruskal(); break;
            case 3: int src; cout << "Enter source: "; cin >> src; dijkstra(src); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}