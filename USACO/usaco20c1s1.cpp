/*
USACO 2020 December Contest, Silver - Problem 1. Cowntagion
Key Concepts: Recursion, Graph Theory
http://www.usaco.org/current/index.php?page=viewproblem&cpid=1050
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<int> adj[MAXN];

int solve(int n, int p) {   // current node, parent node
    int out = ceil(log2((double)adj[n].size()));    // doublings needed
    for (int t:adj[n]) {
        if (t != p) {
            out += solve(t, n) + 1;     // move cows recursively
        }
    }
    return out;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, a, b; cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[1].push_back(0);

    cout << solve(1, 0) << "\n";

    return 0;
}