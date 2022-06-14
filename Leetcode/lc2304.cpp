/*
Leetcode 2304. Minimum Path Cost in a Grid
Key Concepts: Dynamic Programming
https://leetcode.com/problems/minimum-path-cost-in-a-grid/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Idea: Process each row at a time, maintaing the minimum amount of time to arrive at each cell of the next row.
    // Time Complexity: O(M N^2)
    // Space Complexity: O(MN), can be optimized to O(N)
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int M = grid.size();
        int N = grid[0].size();

        // dp[i][j] is the minimum time to arrive at (i, j)
        vector<vector<int>> dp(M, vector<int>(N, 0x3f3f3f3f));
        for (int j = 0; j < N; ++j) {
            dp[0][j] = grid[0][j];
        }

        // update row by row
        for (int r = 0; r+1 < M; ++r) {
            for (int c = 0; c < N; ++c) {
                // starting vertex: grid[r][c]
                // try every possible vertex grid[r+1][t]
                for (int t = 0; t < N; ++t) {
                    dp[r+1][t] = min(dp[r+1][t], dp[r][c] + moveCost[grid[r][c]][t] + grid[r+1][t]);
                }
            }
        }

        // answer is minimum entry in last row
        int ans = 0x3f3f3f3f;
        for (int i : dp[M-1]) ans=min(ans, i);
        return ans;
    }
};
