/*
Leetcode 53. Maximum Subarray
Key Concepts: Dynamic Programming
https://leetcode.com/problems/maximum-subarray/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) { // Let cur[i] denote best subarray ending at index i
            cur = max(nums[i], cur+nums[i]);    // Then cur[i] = max(nums[i], nums[i] + cur[i-1])
            ans = max(ans, cur);
        }
        return ans;
    }
};
