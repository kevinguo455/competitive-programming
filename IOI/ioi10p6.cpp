/*
IOI '10 P6 - Traffic Congestion
Key Concepts: Graph Theory (degree), Greedy Algorithms
https://dmoj.ca/problem/ioi10p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

struct City {int p, n, t;};

bool cmp(City a, City b) {
    return a.p > b.p;
}

vector<int> adj[MAXN];
priority_queue<City, vector<City>, function<bool(City, City)>> pq(cmp);
int deg[MAXN];

int LocateCentre(int N, int W[], int S[], int D[]) {
    // init
    for (int i = 0; i < N-1; i++) {
        adj[S[i]].push_back(D[i]);
        adj[D[i]].push_back(S[i]);
    }
    // grab all corners
    for (int i = 0; i < N; i++) {
        if (adj[i].size() == 1) {
            pq.push({W[i], i, adj[i][0]});
        }
        deg[i] = adj[i].size();
    }
    // greedily collapse graph
    while (pq.size() > 1) {
        City c = pq.top(); pq.pop();
        W[c.t] += c.p;
        deg[c.t]--;
        deg[c.n]--;
        if (deg[c.t] == 1) {
            for (int t : adj[c.t]) {
                if (deg[t]) {
                    pq.push({W[c.t], c.t, t});
                }
            }
        }
    }
    if (pq.empty()) return 0;
    return pq.top().n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int W[N];
    int S[N-1];
    int D[N-1];
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N-1; i++) cin >> S[i] >> D[i];
    cout << LocateCentre(N, W, S, D) << '\n';

    return 0;
}