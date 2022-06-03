/*
Leetcode 152. Maximum Product Subarray
Key Concepts: Dynamic Programming
https://leetcode.com/problems/maximum-product-subarray/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Idea: First assume all numbers are positive. Let b[i] = maximum product subarray ending at index i
    //       Then b[i] = max(nums[i], nums[i] * b[i-1])
    //       Since numbers can be positive or negative, we will store both the running max and running min.
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    int maxProduct(vector<int>& nums) {
        int best = nums[0], cur_lo = nums[0], cur_hi = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            tie(cur_lo, cur_hi) = tie(min(nums[i], min(nums[i]*cur_lo, nums[i]*cur_hi)),
                                      max(nums[i], max(nums[i]*cur_lo, nums[i]*cur_hi)));
            best = max(best, cur_hi);
        }
        return best;
    }
};
