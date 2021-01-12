/*
AtCoder Beginner Contest 188 Problem E - Peddler 
Key Concepts: Graph Theory (Dijkstra's)
https://atcoder.jp/contests/abc188/tasks/abc188_e
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
const int INF = 2*0x3f3f3f3f, MAXN = 2e5+5; 

vector<int> adj[MAXN];
int val[MAXN];
int minval[MAXN];

bool cmp(int a, int b) {
    return minval[a] < minval[b];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int nodes, edges; cin >> nodes >> edges;
    for (int i = 1; i <= nodes; i++) {
        cin >> val[i];
    }
    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    // modified Dijkstra's
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
    ms(minval, INF);
    int ans = 0-INF;

    for (int i = 1; i <= nodes; i++) {
        if (minval[i] != INF) continue;
        pq.push(i);

        while(!pq.empty()) {
            int c = pq.top(); pq.pop();

            ans = max(ans, val[c] - minval[c]);
            minval[c] = min(minval[c], val[c]);
            
            for (int t:adj[c]) {
                if (minval[t] > minval[c]) {
                    minval[t] = minval[c];
                    pq.push(t);
                }
            }
        }
        
    }

    cout << ans << "\n";

    return 0;
}