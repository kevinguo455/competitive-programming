/*
Leetcode 120. Triangle
Key Concepts: Dynamic Programming
https://leetcode.com/problems/triangle/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This problem can be solved by maintaining a 2D dynamic programming
    // table that tracks the minimum total to travel from the top to triangle[i][j].
    //
    // To achieve O(N) space complexity, we can use a 1D dynamic programming table
    // and find the minimum total to travel to each cell, row by row.
    // We must take care to ensure that we do not overwrite past values in the table
    // until we're done using them.
    // 
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0x3f3f3f3f);
        dp[0] = triangle[0][0];
        for (int r = 0; r+1 < triangle.size(); ++r) {
            for (int c = r; c >= 0; --c) {
                dp[c+1] = min(dp[c+1], dp[c]+triangle[r+1][c+1]);
                dp[c] = dp[c]+triangle[r+1][c];
                
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i : dp) ans = min(ans, i);
        return ans;
    }
};
