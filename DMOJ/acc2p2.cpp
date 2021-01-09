/*
Another Contest 2 Problem 2 - Poutine
Key Concepts: Graph Theory (Floyd-Warshall's, reachability)
https://dmoj.ca/problem/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505; 

bool reachable[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n; cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            reachable[i][j] = c == '1';
        }
    }
    
    // Floyd-Warshall's
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reachable[i][j] |= reachable[i][k] && reachable[k][j];
            }
        }
    }

    // count unreachable pairs
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (!reachable[i][j] && !reachable[j][i]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}