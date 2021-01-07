/*
CCC '15 S2 - Jerseys
Key Concepts: Implementation, Greedy Algorithms
https://dmoj.ca/problem/ccc15s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+2;

short arr[MAXN];

short size(char c) {
    if (c == 'S') return 1;         // 1 = small
    else if (c == 'M') return 2;    // 2 = medium
    else return 3;                  // 3 = large
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int j, a; cin >> j >> a;
    char c;
    for (int i = 1; i <= j; i++) {
        cin >> c;                  
        arr[i] = size(c);           // store size of ith jersey
    }

    int ans = 0;
    
    for (int i = 0; i < a; i++) {
        cin >> c >> j;
        if (size(c) <= arr[j]) {    // if jth jersey fits, assign it
            arr[j] = -1;            // -1 = taken
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}