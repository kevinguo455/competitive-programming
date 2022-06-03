/*
Leetcode 238. Product of Array Except Self
Key Concepts: Array Prefixes/Suffixes
https://leetcode.com/problems/product-of-array-except-self/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Idea: answer[i] = product of prefix before i * suffix after i
    // Time Complexity: O(n)
    // Space Complexity: O(1) extra space
    vector<int> productExceptSelf(vector<int>& nums) {
        // Build suffix product array
        vector<int> ans(nums.size());
        ans[nums.size()-1] = 1;
        for (int i = nums.size()-2; i >= 0; --i) {
            ans[i] = ans[i+1] * nums[i+1];
        }
        // Accumulate prefix products
        int pre = 1;
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        return ans;
    }
};
