/*
Leetcode 63. Unique Paths II
Key Concepts: Grid Dynamic Programming
https://leetcode.com/problems/unique-paths-ii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Time Complexity: O(NM)
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[grid.size()-1][grid[0].size()-1]) return 0;

        // dp[i][j] stores the number of valid unique paths ending at (i, j)
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) continue;
                dp[i+1][j] += dp[i][j];
                dp[i][j+1] += dp[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
