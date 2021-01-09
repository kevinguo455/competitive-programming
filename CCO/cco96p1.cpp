/*
CCO '96 P1 - Train Swapping
Key Concepts: Bubble Sort
https://dmoj.ca/problem/cco96p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {
        int n; cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // implement bubble sort
        bool done = 0;
        int swaps = 0;
        while (!done) {
            done = 1;
            for (int i = 0; i < n-1; i++) {
                if (arr[i] > arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    swaps++;
                    done = 0;
                }
            }
        }

        cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }

    return 0;
}