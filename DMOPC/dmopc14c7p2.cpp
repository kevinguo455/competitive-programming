/*
DMOPC '14 Contest 8 P2 - Tides
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc14c7p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005, INF = 0x3f3f3f3f; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    
    int min_val = INF, min_idx = -1;
    int max_val = -INF, max_idx = -1;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_idx = i;
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
    }

    if (max_idx < min_idx) {
        cout << "unknown\n";
        return 0;
    }

    for (int i = min_idx; i < max_idx; i++) {
        if (arr[i] >= arr[i+1]) {
            cout << "unknown\n";
            return 0;
        }
    }

    cout << max_val - min_val << '\n';

    return 0;
}