#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int s[n], max1 = 0, max2 = 0;
    
    // Read input and determine max1 and max2
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] > max1) {
            max2 = max1;
            max1 = s[i];
        } else if (s[i] > max2) {
            max2 = s[i];
        }
    }

    // Compute and print results
    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            cout << s[i] - max2 << " ";
        } else {
            cout << s[i] - max1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
