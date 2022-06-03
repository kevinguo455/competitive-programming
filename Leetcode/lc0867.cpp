/*
Leetcode 867. Transpose Matrix
Key Concepts: Implementation
https://leetcode.com/problems/transpose-matrix/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(MN)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> ans(N, vector<int>(M));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
