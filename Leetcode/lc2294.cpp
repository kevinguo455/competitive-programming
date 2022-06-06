/*
Leetcode 2294. Partition Array Such That Maximum Difference Is K
Key Concepts: Sorting, Greedy Algorithms
https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Observation 1: The problem is equivalent to finding the minimum amount of intervals of length k
//                required to cover all the points in nums.
// Observation 2: The smallest number in nums must be covered by an interval.
//                Let the smallest number in nums be a. Then we can greedily pick the interval [a, a+k]
//                since there are no numbers smaller than a.
// Idea: Sort nums, then repeatedly take intervals of the form [a, a+k] where a is the smallest uncovered number.

// Time Complexity: O(NlogN)
// Space Complexity: O(1) extra space, O(N) total space (nums is modified)

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        auto it = nums.begin();         // Invariant: it points to the smallest uncovered number
        while (it != nums.end()) {
            ++ans;
            it = upper_bound(it, nums.end(), *it+k);
        }
        return ans;
    }
};
