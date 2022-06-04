/*
Leetcode 51. N-Queens
Key Concepts: Recursion
https://leetcode.com/problems/n-queens/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^N)
// Space Complexity: O(N^2)

class Solution {
    int N;
    vector<string> lines, cur;  // lines is precomputed ["Q...", ".Q..", "..Q.", etc.]
                                // cur is the current state of board
    vector<vector<string>> ans; // ans is answer to return (all valid boards)
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
    // tracking the current state (where future queens can be placed) and the result so far
    void solve(vector<vector<int>>& state, int r, vector<string>& res) {
        if (r == N) {
            ans.push_back(res); // done placing all N queens
            return;
        }
        for (int c = 0; c < N; ++c) {
            if (!state[r][c]) {             // if queen can be placed at (r, c)
                fan_down(state, r, c, 1);   // update state
                res.push_back(lines[c]);    // update result

                solve(state, r+1, res);     // recursively solve
                
                fan_down(state, r, c, -1);  // restore state
                res.pop_back();             // restore result
            }
        }
    }

public:
    // Main function
    vector<vector<string>> solveNQueens(int n) {
        
        // initialize global variables
        N = n;
        lines.assign(n, string(n, '.'));
        for (int i = 0; i < n; ++i) lines[i][i] = 'Q';
        state.assign(n, vector<int>(n, 0));

        // create references
        vector<vector<int>>& s = state;
        vector<string>& r = cur;
        
        // recursively solve
        solve(s, 0, r);
        return ans;
    }
};
