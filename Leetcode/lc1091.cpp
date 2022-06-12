/*
Leetcode 1091. Shortest Path in Binary Matrix
Key Concepts: Grid BFS
https://leetcode.com/problems/shortest-path-in-binary-matrix/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

bool vis[MAXN][MAXN];

class Solution {

public:

    // Idea: Run BFS from the top left corner of the grid.

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        if (!grid[0][0]) q.push({0, 0});

        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        int end = grid.size()-1;
        int dist = 1;

        while (!q.empty()) {

            // BFS with maintaining distance
            int s = q.size();
            while (s--) {
                pair<int, int> c = q.front(); q.pop();

                // reached end!
                if (c.first == end && c.second == end) return dist;

                // iterate through the 8 neighbours
                for (int i = max(c.first-1, 0); i <= min(c.first+1, end); ++i) {
                    for (int j = max(c.second-1, 0); j <= min(c.second+1, end); ++j) {
                        if (!grid[i][j] && !vis[i][j]) {
                            q.push({i, j});
                            vis[i][j] = 1;
                        }
                    }
                }
            }
            ++dist;
        }

        // end not reached
        return -1;
    }

};
