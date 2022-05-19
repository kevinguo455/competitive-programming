/*
Leetcode 300. Longest Increasing Subsequence
Key Concepts: Dynamic Programming (LIS)
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i-1] is the smallest last element of increasing subsequences of length i
        vector<int> dp;
        for (int n : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), n);
            if (it == dp.end()) dp.push_back(n);
            else *it = n;
        }
        return dp.size();
    }
};
