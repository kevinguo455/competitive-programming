/*
WC '18 Contest 4 S1 - World of StarCraft
Key Concepts: Graph Theory (Components)
https://dmoj.ca/problem/wc18c4s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int N, E, Q;
string S;

vector<int> adj[MAXN];
int c[MAXN];        // the "colour" of each node (i.e. the component it belongs to)

// colours all nodes reachable from this node
void dfs(int n, int idx) {
    c[n] = idx;
    for (int t:adj[n]) {
        if (!c[t]) {
            dfs(t, idx);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    cin >> N >> E >> Q;
    cin >> S;
    
    // build graph
    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b; a--; b--;    // 0-indexed
        if (S[a] == S[b]) {         // only add edges between two planets controlled by the same race
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    // detect connected components
    int idx = 1;
    for (int i = 0; i < N; i++) {
        if (!c[i]) {    // run DFS on each uncoloured node
            dfs(i, idx);
            idx++;
        }
    }

    // answer queries by checking if they have the same colour
    int ans = 0;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b; a--; b--;
        if (c[a] == c[b]) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}