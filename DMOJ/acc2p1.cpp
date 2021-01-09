/*
Another Contest 2 Problem 1 - Poutine
Key Concepts: Dynamic Programming, Graph Theory (Floyd-Warshall's)
https://dmoj.ca/problem/acc2p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
typedef long long ll;
const int MAXN = 102; 
const ll INF = 0x3f3f3f3f3f3f3f3f;

// (0-indexed)
ll dist[MAXN][MAXN][MAXN]; // shortest path between i and j that takes at most k stops (k+1 days)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    ms(dist, INF);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j][0];
            if (i == j) dist[i][j][0] = 0;
            else if (dist[i][j][0] == 0) dist[i][j][0] = INF;
        }
    }

    // Floyd-Warshall's 
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j][0] = min(dist[i][j][0], dist[i][k][0] + dist[k][j][0]);
            }
        }
    }

    // dp
    for (int d = 1; d < n; d++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j][d] = min(dist[i][j][d], max(dist[i][k][d-1], dist[k][j][0]));
                }
            }
        }
    }

    // queries
    int q, i, j, k; cin >> q;
    for (int qn = 0; qn < q; qn++) {
        cin >> i >> j >> k;
        if (dist[i-1][j-1][k-1] == INF) cout << "0\n";
        else cout << dist[i-1][j-1][k-1] << "\n";
    }

    return 0;
}