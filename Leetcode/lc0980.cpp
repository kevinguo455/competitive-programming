/*
Leetcode 980. Unique Paths III
Key Concepts: DFS, Bitmasks
https://leetcode.com/problems/unique-paths-iii/
Solution by Kevin Guo
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int N, M, END_STATE, END_I, END_J, ans;
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // maps a cell (i, j) to an integer in the range [0, N*M]
    inline int get_digit(int i, int j) {
        return i*M+j;
    }

    // maps an integer in the range [0, N*M] to the bit that represents it
    inline int get_mask(int i, int j) {
        return 1 << get_digit(i, j);
    }

    // checks whether (i, j) is in range of the grid
    inline bool is_valid(int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }

    // checks if the bit representing (i, j) is set in the state
    inline bool is_set(int state, int i, int j) {
        return state & get_mask(i, j);
    }

    // performs DFS from a given cell (i, j)
    // state tracks the cells that were already visited
    void dfs(int state, int i, int j) {
        // mark (i, j) as visited
        state |= get_mask(i, j);

        // stop searching when all cells visited
        if (state == END_STATE)  {
            if (i == END_I && j == END_J) ++ans;  // reached end
            return;
        }

        // try all 4 directions
        for (auto dir : dirs) {
            int ti = i+dir[0];
            int tj = j+dir[1];
            // search only if the target cell (ti, tj) is valid and not already visited
            if (is_valid(ti, tj) && !is_set(state, ti, tj)) {
                dfs(state, ti, tj);
            }
        }
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        // initialize global variables
        ans = 0;
        N = grid.size();
        M = grid[0].size();
        END_STATE = (1<<(N*M))-1;

        // mark obstacles as "visited" cells in the state; find the ending cell
        int state = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == -1) {
                    state |= get_mask(i, j);
                } else if (grid[i][j] == 2) {
                    END_I = i;
                    END_J = j;
                }
            }
        }

        // run DFS from the starting cell
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) dfs(state, i, j);
            }
        }
        return ans;
    }
};
