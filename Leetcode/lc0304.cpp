/*
Leetcode 304. Range Sum Query 2D - Immutable
Key Concepts: 2D Prefix Sum Array
https://leetcode.com/problems/range-sum-query-2d-immutable/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> psa; // psa[i+1][j+1] is the sum of the elements in the rectangle with corners (0, 0), (i, j)

public:
    NumMatrix(vector<vector<int>>& matrix) : psa{matrix.size()+1, vector<int>(matrix[0].size()+1, 0)} {
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                psa[i][j] = (long long) psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (long long) psa[row2+1][col2+1] - psa[row2+1][col1] - psa[row1][col2+1] + psa[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
