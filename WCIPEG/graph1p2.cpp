/*
Shortest Path
Key Concepts: Graph Theory (BFS/DFS)
https://dmoj.ca/problem/graph1p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const short MAXN = 101; 

bitset<MAXN*MAXN> adj;
bitset<MAXN> vis;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    short N; cin >> N;
    bool x;
    for (short i = 0; i < N; i++) {
        for (short j = 0; j < N; j++) {
            cin >> x;
            adj[i*MAXN+j] = x;
        }
    }

    short ans = 0;
    queue<short> q;
    q.push(0); 
    vis[0] = 1;

    while (!q.empty()) {
        short s = q.size();
        while (s--) {
            short c = q.front();
            q.pop();

            if (c == N-1) {
                cout << ans << "\n";
                return 0;
            }

            for (short t = 0; t < N; t++) {
                if (!vis[t] && adj[c*MAXN+t]) {
                    q.push(t);
                    vis[t] = 1;
                }
            }
        }
        ans++;
    }

    return 0;
}