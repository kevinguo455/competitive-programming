/*
Travelling Salesmen
Key Concepts: Graph Theory (Multisource BFS)
https://dmoj.ca/problem/graph3p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4+5;

vector<int> adj[MAXN];
bool vis[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, E; cin >> N >> E;
    int a, b;
    while (E--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    int K; cin >> K;
    while (K--) {
        cin >> a;
        q.push(a);
        vis[a] = 1;
    }
    
    int ans = -1;
    while (!q.empty()) {
        int s = q.size();
        while (s--) {
            int c = q.front(); q.pop();
            for (int t : adj[c]) {
                if (vis[t]) continue;
                q.push(t);
                vis[t] = 1;
            }
        }
        ans++;
    }
    cout << ans << "\n";

    return 0;
}