/*
CCC '21 S4 - Daily Commute
Key Concepts: Graph Theory
https://dmoj.ca/problem/ccc21s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, M, D;
vector<int> adj[MAXN];
int dist[MAXN];
int order[MAXN];
multiset<int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> D;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    memset(dist, 0x3f, sizeof dist);
    dist[N] = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        int tdist = dist[c] + 1;
        for (int t : adj[c]) {
            if (tdist < dist[t]) {
                dist[t] = tdist;
                q.push(t);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cin >> order[i];
        ans.insert(i + dist[order[i]]);
    }

    for (int i = 0, a, b; i < D; i++) {
        cin >> a >> b; a--; b--;
        ans.erase(ans.find(a + dist[order[a]]));
        ans.erase(ans.find(b + dist[order[b]]));
        swap(order[a], order[b]);
        ans.insert(a + dist[order[a]]);
        ans.insert(b + dist[order[b]]);
        cout << *ans.begin() << '\n';
    }

    return 0;
}