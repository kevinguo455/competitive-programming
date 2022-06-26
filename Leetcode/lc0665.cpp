/*
Leetcode 665. Non-decreasing Array
Key Concepts: Implementation
https://leetcode.com/problems/non-decreasing-array/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(1) additional space

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // track whether the one modification has been used yet
        bool modified = false;
        for (int i = 0; i+1 < nums.size(); ++i) {
            if (nums[i] > nums[i+1]) {
                if (modified) return false;
                modified = 1;
                if (i == 0 || nums[i-1] <= nums[i+1]) continue;             // can set nums[i] to nums[i+1]
                if (i == nums.size()-2 || nums[i] <= nums[i+2]) continue;   // can set nums[i+1] to nums[i]
                return false;   // no valid solution
            }
        }
        return true;
    }
};
