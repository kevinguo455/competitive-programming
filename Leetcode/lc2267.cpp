/*
Leetcode 2267. Check if There Is a Valid Parentheses String Path
Key Concepts: Dynamic Programming
https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

class Solution {
public:

    // Time Complexity: O(MN max(M, N))
    // State: dp[i][j][k] stores whether it is possible to get to (i, j) with k extra open brackets
    // Transition: If grid[i][j] == '(', then dp[i][j][k+1] == dp[i-1][j][k] || dp[i][j-1][k]
    //                          i.e. if you can get to the up or left cell with k extra open brackets,
    //                               then you can get to the current cell with k+1 extra open brackets
    //             If grid[i][j] == ')', then dp[i][j][k-1] == dp[i-1][j][k] || dp[i][j-1][k]
    //                          i.e. similar logic as above, but need to make sure k-1 >= 0
    bool hasValidPath(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        vector<vector<bitset<MAXN>>> dp(M, vector<bitset<MAXN>>(N));

        if (grid[0][0] == '(') dp[0][0][1] = 1;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int d = grid[i][j] == '(' ? 1 : -1;
                if (i != 0) {
                    if (d == 1 && dp[i-1][j][0]) dp[i][j][1] = 1;
                    for (int k = 1; k < MAXN-1; ++k) {
                        if (dp[i-1][j][k]) dp[i][j][k+d] = 1;
                    }
                } 
                if (j != 0) {
                    if (d == 1 && dp[i][j-1][0]) dp[i][j][1] = 1;
                    for (int k = 1; k < MAXN-1; ++k) {
                        if (dp[i][j-1][k]) dp[i][j][k+d] = 1;
                    }
                }
            }
        }

        return dp[M-1][N-1][0];
    }
};
