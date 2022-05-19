/*
Leetcode 1192. Critical Connections in a Network
Key Concepts: Bridge Finding in a Graph
https://leetcode.com/problems/critical-connections-in-a-network/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Tarjan's Bridge Finding Algorithm
class Solution {
    vector<int> low;
    vector<bool> vis;
    vector<int> in;
    vector<vector<int>> adj;
    int idx;

public:

    void dfs(int c, int p, vector<vector<int>>& bridges) {
        vis[c] = 1;
        in[c] = low[c] = idx++;
        for (int t : adj[c]) {
            if (t == p) continue;
            if (vis[t]) {
                low[c] = min(low[c], in[t]);
            } else {
                dfs(t, c, bridges);
                low[c] = min(low[c], low[t]);
                if (low[t] > in[c]) {
                    bridges.push_back({c, t});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // reset variables
        idx = 0;
        in.resize(n);
        low.assign(n, -1);
        vis.assign(n, false);
        adj.assign(n, vector<int>());

        // build adjacency list
        for (vector<int> edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // find bridges using Tarjan's Algorithm
        vector<vector<int>> ans;
        dfs(0, -1, ans);        // note that the given graph is connected
        return ans;
    }
};
