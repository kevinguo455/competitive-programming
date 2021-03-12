/*
CCC '06 J4 - It's tough being a teen!
Key Concepts: Graph Theory (topological sort, cycle detection)
https://dmoj.ca/problem/ccc06j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8; 

vector<int> adj[MAXN];
short vis[MAXN];
stack<int> ans;
bool cycle;

void dfs(int c) {
    vis[c] = 1;
    for (int t : adj[c]) {
        if (vis[t] == 1) {
            cycle = 1;
            return;
        }
        if (vis[t] == 0) dfs(t);
    }
    vis[c] = 2;
    ans.push(c);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // add default restrictions
    adj[1].push_back(7);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);

    // add additional restrictions
    int a, b; cin >> a >> b;
    while (a != 0) {
        adj[a].push_back(b);
        cin >> a >> b;
    }

    // sort in reverse order to choose lower numbers first
    for (int i = 1; i < MAXN; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }

    // topological sort
    for (int i = MAXN-1; i >= 1; i--) {
        if (!vis[i]) dfs(i);
    }

    if (cycle) cout << "Cannot complete these tasks. Going to bed.";
    else {
        while (!ans.empty()) { 
            cout << ans.top() << ' ';
            ans.pop();
        }
    }
    cout << '\n';

    return 0;
}