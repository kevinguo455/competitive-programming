/*
Leetcode 52. N-Queens II
Key Concepts: Recursion
https://leetcode.com/problems/n-queens-ii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// This solution is very similar to my solution to Leetcode 50. N-Queens

// Time Complexity: O(N^N)
// Space Complexity: O(N^2)

class Solution {
    int N, ans = 0;             // N is size of board, ans is answer to return
    vector<vector<int>> state;  // state[i][j] = 0 if a queen can be placed at (i, j), state[i][j] > 0 otherwise

    // fan_down(state, r, c, 1) places a queen at (r, c) and marks the cells below (r, c) as attacked by the queen
    // fan_down(state, r, c, -1) undos the above operation, removing the queen at (r, c)
    void fan_down(vector<vector<int>>& state, int r, int c, int d) {
        for (int i = 1; r+i < N; ++i) {
            state[r+i][c] += d;
            if (c+i < N) state[r+i][c+i] += d;
            if (c-i >= 0) state[r+i][c-i] += d;
        }
    }

    // Recursive function that places a queen in a given row r, 
    // tracking the current state (where future queens can be placed)
    void solve(vector<vector<int>>& state, int r) {
        if (r == N) {
            ++ans;      // done placing all N queens
            return;
        }
        for (int c = 0; c < N; ++c) {
            if (!state[r][c]) {             // if queen can be placed at (r, c)
                fan_down(state, r, c, 1);   // update state
                solve(state, r+1);          // recursively solve
                fan_down(state, r, c, -1);  // restore state
            }
        }
    }

public:
    // Main function
    int totalNQueens(int n) {
        
        // initialize global variables
        N = n;
        state.assign(n, vector<int>(n, 0));

        // create references
        vector<vector<int>>& s = state;

        // recursively solve
        solve(s, 0);
        return ans;
    }
};
