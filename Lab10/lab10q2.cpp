#include <map>
#include <iostream>
using namespace std;
#include <vector>
#include <string>


void solve(){
    int n;
    cout << "enter number of array elements: ";
    cin >> n;
    cout << endl;
    vector<string> allword(3*n);
    vector<int>scores (3,0);
    map<string, int> wordcount;
    for (int i = 0; i < 3 * n; i++) {
        cin >> allword[i]; 
        wordcount[allword[i]]++;
    }
    for (int i = 0; i < 3 * n; i++){
        int player = i / n; // Determine which player wrote this word
        int frequency = wordcount[allword[i]];

        if (frequency == 1) scores[player] += 3;
        else if (frequency == 2) scores[player] += 1;
    }
    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
}



int main(){
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cout << endl;

    while (t--)
    {
        solve();
    }
    return 0;
}