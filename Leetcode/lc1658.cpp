/*
Leetcode 1658. Minimum Operations to Reduce X to Zero
Key Concepts: Two Pointers
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Observation 1: Instead of considering removing elements from the left and right ends,
    //                we will consider keeping a subarray (in the middle).
    //                Thus we are finding the longest subarray that sums to T-x, where T
    //                is the sum of all elements in nums.
    // Idea: For each possible left endpoint, find the first right endpoint such that [l, r]
    //       has sum greater than T-x.
    //       We can find this using a two pointer approach.
    //
    // Time Complexity: O(N), where N = nums.size()
    // Space Complexity: O(1) 
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum < x) return -1;

        int r = 0, ans = 0x3f3f3f3f, N = nums.size();
        for (int l = 0; l < N; ++l) {
            while (sum > x && r < N) {
                sum -= nums[r];
                ++r;
            }
            if (sum == x) ans = min(ans, N-(r-l));
            sum += nums[l];
        }

        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};
