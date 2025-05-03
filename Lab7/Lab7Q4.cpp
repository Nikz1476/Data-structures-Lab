#include <iostream>
#include <stack>
using namespace std;

string processString(const string &ip) {
    stack<char> s;
    
    for (char ch : ip) {
        if (ch == '+') { 
            if (!s.empty()) {
                s.pop();  // Remove last valid character
            }
        } else {
            s.push(ch); // Always push valid characters
        }
    }

    string result;
    while (!s.empty()) {
        result = s.top() + result; 
        s.pop();
    }

    return result;
}

int main() {
    string ip;
    cout << "Enter the input string with '+': ";
    cin >> ip;

    string op = processString(ip);
    cout << "Output: " << op << endl;  // Print the final result
    return 0;
}
