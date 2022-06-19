/*
Leetcode 2312. Selling Pieces of Wood
Key Concepts: Dynamic Programming
https://leetcode.com/problems/selling-pieces-of-wood/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 205;

class Solution {
public:
    // dp[i][j] is the maximum sell value of an (i x j) piece of wood
    // Base Case: dp[h][w] = p, for every (h x w) piece with price p given in prices
    // Transition: Try split every piece vertically and horizontally, along every possible line
    //
    // Time Complexity: O(P + MN(M+N)), where P = prices.size()
    // Space Complexity: O(MN)
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(MAXN, vector<ll>(MAXN, 0));

        // Initialize base case
        for (vector<int>& v : prices) {
            dp[v[0]][v[1]] = max(dp[v[0]][v[1]], (ll)v[2]);
        }

        // Compute dp[i][j] bottom-up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // We are computing the max sell value of an (i x j) piece of wood

                // Try every horizontal split
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i-k][j]);
                }
                // Try every vertical split
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j-k]);
                }
            }
        }
        
        return dp[m][n];
    }
};
