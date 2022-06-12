/*
Leetcode 167. Two Sum II - Input Array Is Sorted
Key Concepts: Two Pointers
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Standard two pointers approach
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while (l < r) {
            if (numbers[l] + numbers[r] < target) {
                ++l;
            } else if (numbers[l] + numbers[r] > target) {
                --r;
            } else {
                return {l+1, r+1}; // since array is 1-indexed
            }
        }
        // this should never occur since there is exactly one solution
        return {-1, -1};
    }
};
