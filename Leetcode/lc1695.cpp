/*
Leetcode 1695. Maximum Erasure Value
Key Concepts: Two Pointers
https://leetcode.com/problems/maximum-erasure-value/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1e4+5;

class Solution {
public:
    // Observation: If the elements in [l, r] are unique, then the elements
    //              in [l+1, r] are also unique.
    // Idea: Use a two pointers approach to find the maximal r such that 
    //       [l, r] is unique for all l. Keep track of the running sum.
    // Time Complexity: O(N), where N = nums.size()
    // Space Complexity: O(V), where V is the largest integer in nums
    int maximumUniqueSubarray(vector<int>& nums) {
        bitset<MAXV> seen;
        int r = 0, sum = 0, best = 0;
        for (int l = 0; l < nums.size(); ++l) {
            while (r < nums.size() && !seen[nums[r]]) {
                sum += nums[r];
                seen[nums[r]] = 1;
                ++r;
            }
            best = max(best, sum);
            sum -= nums[l];
            seen[nums[l]] = 0;
        }
        return best;
    }
};
