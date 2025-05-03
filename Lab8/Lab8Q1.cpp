#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> towers(n);
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }
    
    int a1 = towers[0];
    long long extra_blocks = 0;  

    for (int i = 1; i < n; i++) {
        if (towers[i] > a1) {
            extra_blocks += (towers[i] - a1);
        }
    }

    cout << (a1 + extra_blocks) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
