/*
Leetcode 2267. Check if There Is a Valid Parentheses String Path
Key Concepts: Memoization, Recursion
https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int M, N;
bitset<MAXN> vis[MAXN][MAXN];   // vis[i][j][p] stores whether the state solve(i, j, p, grid) has been visited
bitset<MAXN> dp[MAXN][MAXN];    // dp[i][j][p] stores the result of solve(i, j, p, grid)

class Solution {
public:

    // Time Complexity: O(MN max(M, N))
    // Returns if it is possible to get to (i, j) with p extra open brackets
    bool solve(int i, int j, int p, vector<vector<char>>& grid) {
        if (i == M || j == N) return false;     // state out of bounds
        if (vis[i][j][p]) return dp[i][j][p];   // state already visited
        int d = grid[i][j] == '(' ? 1 : -1;
        vis[i][j][p] = true; 
        if (p+d < 0) return dp[i][j][p] = false;    // not enough open brackets to support another close bracket
        if (i == M-1 && j == N-1) return p+d == 0;  // try going down and going right
        return dp[i][j][p] = (solve(i+1, j, p+d, grid) || solve(i, j+1, p+d, grid));
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        return solve(0, 0, 0, grid);
    }

};
