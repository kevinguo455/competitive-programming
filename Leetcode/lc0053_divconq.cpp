/*
Leetcode 53. Maximum Subarray
Key Concepts: Divide and Conquer
https://leetcode.com/problems/maximum-subarray/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Val {
        int t;  // total sum
        int l;  // best sum including left endpoint
        int r;  // best sum including right endpoint
        int b;  // best sum
    };

public:
    Val solve(int l, int r, vector<int>& nums) {
        if (l == r) return {nums[l], nums[l], nums[l], nums[l]};
        Val lc = solve(l, (l+r)/2, nums);
        Val rc = solve((l+r)/2+1, r, nums);
        return {lc.t + rc.t, 
                max(lc.l, lc.t + rc.l),
                max(rc.r, lc.r + rc.t),
                max(max(lc.b, rc.b), lc.r+rc.l)};
    }

    // Time Complexity: O(n log n)
    int maxSubArray(vector<int>& nums) {
        return solve(0, nums.size()-1, nums).b;
    }
};
