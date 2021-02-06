/*
Connected Components
Key Concepts: Graph Theory
https://dmoj.ca/problem/graph2p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;

bool adj[MAXN][MAXN];
bool vis[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(i);
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (int j = 1; j <= n; j++) {
                if (vis[j]) continue;
                if (!adj[c][j]) continue;
                pq.push(j);
                q.push(j);
                vis[j] = 1;
            }
        }
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
    }

    return 0;
}