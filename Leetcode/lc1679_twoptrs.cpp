/*
Leetcode 1679. Max Number of K-Sum Pairs
Key Concepts: Two Pointers
https://leetcode.com/problems/max-number-of-k-sum-pairs/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Approach: Sort array, then perform two-pointer algorithm.
// Time Complexity: O(n log n)

int maxOperations(vector<int> nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 0, left = 0, right = nums.size()-1;
    while (left < right && nums[left] < k) {
        if (nums[left] + nums[right] > k) {
            --right;
        } else if (nums[left] + nums[right] < k) {
            ++left;
        } else {
            --right;
            ++left;
            ++ans;
        }
    }
    return ans;
}
