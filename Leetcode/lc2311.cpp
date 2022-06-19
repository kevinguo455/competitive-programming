/*
Leetcode 2311. Longest Binary Subsequence Less Than or Equal to K
Key Concepts: Greedy Algorithms
https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Greedily take 1s and 0s from the end of the string until no more 1s can be taken.
// Then take every 0 that occurs.

class Solution {
public:
    // Time Complexity: O(N), where N = s.size()
    // Space Complexity: O(1)
    int longestSubsequence(string s, int k) {
        int ans = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (k == 0) {
                if (s[i] == '0') ++ans;
            } else {
                ++ans;
                if (s[i] == '1') --k;
                k /= 2;
            }
        }
        return ans;
    }
};
