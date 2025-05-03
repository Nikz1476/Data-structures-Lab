//To find minimum number of elements that can be removed from begining to have an array without duplicate elements
#include <unordered_set>
#include <iostream>
using namespace std;
#include <vector>

void solve(){
    int n;
    cout << "enter number of array elements: ";
    cin >> n;
    cout << endl;
    vector<int> arr(n);
    for (int i =0; i<n; i++)    {
        cout<<"element "<< i <<":";
        cin>>arr[i];
    }

    int prefixlength = 0;
    unordered_set<int> seen;
    for (int i = n-1; i>0; i--)    {
        if(seen.find(arr[i]) != seen.end()){
            break;//if duplicates found
        }
        seen.insert(arr[i]);
        prefixlength+=1;
    }
    cout << " minimum number of elements to be deleted to have an array without duplicates: " << n-prefixlength ;

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