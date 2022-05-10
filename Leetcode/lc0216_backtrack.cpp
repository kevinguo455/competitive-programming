/*
Leetcode 216. Combination Sum III
Key Concepts: Backtracking
https://leetcode.com/problems/combination-sum-iii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;

public:
    // solve(k, n, cur, m) appends to ans the combinations that
    //   contain the integers in cur, with:
    //      k additional integers
    //      that sum up to n
    //      and are each at least m.
    void solve(int k, int n, vector<int> cur, int m) {
        if (k == 0 && n == 0) {
            ans.push_back(cur);
        } else if (k > 0 && n >= m && m <= 9) {
            cur.push_back(m);           // Include m
            solve(k-1, n-m, cur, m+1);
            cur.pop_back();             // Not including m
            solve(k, n, cur, m+1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> cur;
        solve(k, n, cur, 1);
        return ans;
    }
};
