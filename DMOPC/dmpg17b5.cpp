/*
DMPG '17 B5 - Hackathons
Key Concepts: Implementation 
https://dmoj.ca/problem/dmpg17b5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, t, w; cin >> N;
    while (N--) {
        cin >> t >> w;
        arr[t] = max(arr[t], w);
    }
    // build prefix max array
    for (int i = 1; i < MAXN; i++) {
        arr[i] = max(arr[i-1], arr[i]);
    }

    int Q; cin >> Q;
    while (Q--) {
        cin >> t;
        cout << arr[t] << '\n';
    }

    return 0;
}