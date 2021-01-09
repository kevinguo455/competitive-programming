/*
Sorting 
Key Concepts: Implementation
https://dmoj.ca/problem/a4b1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // implement bubble sort
    bool done = 0;
    while (!done) {
        done = 1;
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                done = 0;
            }
        }
    }

    for (int n : arr) {
        cout << n << "\n";
    }

    return 0;
}