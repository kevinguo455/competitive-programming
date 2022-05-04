/*
Leetcode 1679. Max Number of K-Sum Pairs
Key Concepts: Data Structures (set)
https://leetcode.com/problems/max-number-of-k-sum-pairs/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Approach: Scan through array and keep track of "unmatched" numbers in a multiset.
// Time Complexity: O(n log n)

int maxOperations(vector<int>& nums, int k) {
    multiset<int> s;
    int ans = 0;
    for (int n : nums) {
        auto it = s.find(k-n);
        if (it == s.end()) {
            s.insert(n);
        } else {
            s.erase(it);
            ++ans;
        }
    }
    return ans;
}
