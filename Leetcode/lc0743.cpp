/*
Leetcode 743. Network Delay Time
Key Concepts: Dijkstra's Algorithm (Single Source Shortest Path Problem)
https://leetcode.com/problems/network-delay-time/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6005, INF = 0x3f3f3f3f;

struct Edge {int n, d;};

vector<Edge> adj[MAXN];
int dist[MAXN];
bitset<MAXN> inq;

bool cmp(int a, int b) {
    return dist[a] > dist[b];
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // initialize adjacency list
        for (int i = 0; i < MAXN; ++i) adj[i].clear();
        for (vector<int> v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        // initialize helper data structures
        memset(dist, 0x3f, sizeof(dist));
        inq.reset();
        dist[k] = 0;
        priority_queue<int, vector<int>, function<bool(int,int)>> pq(cmp);
        pq.push(k);

        // Dijkstra's Algorithm
        while (!pq.empty()) {
            int c = pq.top(); pq.pop();
            inq[c] = 0;
            for (Edge t : adj[c]) {
                if (dist[c] + t.d < dist[t.n]) {
                    dist[t.n] = dist[c] + t.d;
                    if (!inq[t.n]) pq.push(t.n);
                    inq[t.n] = 1;
                }
            }
        }

        // find the furthest node
        int ans = -1;
        for (int i = 1; i <= n; ++i) ans = max(ans, dist[i]);
        return ans == INF ? -1 : ans;
    }
};
