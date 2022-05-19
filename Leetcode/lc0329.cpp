/*
Leetcode 329. Longest Increasing Path in a Matrix
Key Concepts: Recursion, Memoization
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Top-down dynamic programming to find the longest increasing path
//       ending at any given cell of the matrix.

class Solution {
    vector<vector<int>> dp;
    const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    // Cardinal directions

public:

    // Check if (i, j) is a valid cell in the matrix
    inline bool in_range(int i, int j, vector<vector<int>>& matrix) {
        return i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size();
    }

    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j]) return dp[i][j];
        dp[i][j] = 1;
        for (auto t : dirs) {
            int ti = i+t[0];
            int tj = j+t[1];
            if (in_range(ti, tj, matrix) && matrix[i][j] > matrix[ti][tj]) {
                dp[i][j] = max(dp[i][j], solve(ti, tj, matrix)+1);
            }
        }
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                ans = max(ans, solve(i, j, matrix));
            }
        }
        return ans;
    }
};
