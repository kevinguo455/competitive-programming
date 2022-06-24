/*
Leetcode 2050. Parallel Courses III
Key Concepts: Memoization
https://leetcode.com/problems/parallel-courses-iii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Memoization Solution: Recursively solve for the minimum time complete each course,
//                       and memoize results
// Time Complexity: O(V+E)
// Space Complexity: O(V+E)

class Solution {
    vector<vector<int>> radj;   // reversed adjacency list of the relations graph
    vector<int> dp;             // memoization array, dp[i] is minimum time to complete course i
    
    int solve(int v, vector<int>& time) {   // solve for dp[v]
        if (dp[v]) return dp[v];

        for (int p : radj[v]) {
            dp[v] = max(dp[v], solve(p, time));
        }
        dp[v] += time[v-1];
        return dp[v];
    }
    
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // initialize dp array and adjacency list
        dp.assign(n+1, 0);
        radj.resize(n+1);
        for (vector<int>& v : relations) {
            radj[v[1]].push_back(v[0]);
        }
        // find maximum time
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, solve(i, time));
        }
        return ans;
    }
};

// An alternate solution using topological sort:
//  Traverse the graph in topological sort order, and propagate the time required down to its children.
// Time Complexity: O(V+E)
// Space Complexity: O(V+E)

/*
class Solution {
public:
    // BFS implementation of topological sort
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // find indegrees and build adjacency list
        vector<int> inDeg(n+1, 0);
        vector<vector<int>> adj(n+1, vector<int>());
        for (vector<int>& v : relations) {
            ++inDeg[v[1]];
            adj[v[0]].push_back(v[1]);
        }
        // enqueue roots
        queue<int> q;
        vector<bool> inq(n+1, false);
        vector<int> finish(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if (inDeg[i] == 0) {
                inq[i] = true;
                finish[i] = time[i];
                q.push(i);
            }
        }
        // perform BFS
        int ans = 0;
        while (!q.empty()) {
            int c = q.front(); q.pop();
            for (int t : adj[c]) {
                finish[t] = max(finish[t], finish[c] + time[t]);
                --inDeg[t];
                if (!inq[t] && inDeg[t] == 0) {
                    inq[t] = 1;
                    q.push(t);
                }
            }
            ans = max(ans, finish[c]);
        }
        return ans;
    }
};
*/
