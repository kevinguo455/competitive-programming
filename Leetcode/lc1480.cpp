/*
Leetcode 1480. Running Sum of 1d Array
Key Concepts: Running Sum
https://leetcode.com/problems/running-sum-of-1d-array/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums);
        for (int i = 1; i < ans.size(); ++i) {
            ans[i] += ans[i-1]; // Running sum at index i = running sum at index i-1 + nums[i]
        }
        return ans;
    }
};
