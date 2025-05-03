#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    
    vector<int> a(k);  // Stores elimination positions
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    vector<int> queries(q);  // Stores queries (different n values)
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    // Answer each query
    for (int n : queries) {
        int remaining = n;  // Start with all players
        for (int i = 0; i < k; i++) {
            if (a[i] <= remaining) {  
                // If a[i] is a valid position (<= n), one player is removed
                remaining--;
            } else {
                break; // No more eliminations possible
            }
        }
        cout << remaining << " ";  // Print result for this n
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        solve();  // Solve each test case
    }
    return 0;
}
