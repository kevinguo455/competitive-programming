/*
Range Max Query
Key Concepts: Data Structures (Sparse Table)
https://dmoj.ca/problem/oly18novp4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5, MAXK = 17; 

int st[MAXN][MAXK];
int lg2[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int N, Q; cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> st[i][0];
    }

    // build sparse table
    for (int j = 1; j < MAXK; j++) {
        for (int i = 0; i + (1 << j) <= N; i++) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    // precompute log2s
    for (int i = 2; i <= N; i++) {
        lg2[i] = lg2[i/2] + 1;
    }

    // answer queries
    int l, r, k;
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        k = lg2[r-l+1];
        cout << max(st[l-1][k], st[r-(1<<k)][k]) << "\n";   // sparse table is 0-indexed, queries are 1-indexed
    }

    return 0;
}