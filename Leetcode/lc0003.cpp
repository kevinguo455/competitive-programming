/*
Leetcode 3. Longest Substring Without Repeating Characters
Key Concepts: Sliding Window
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(c), where c is the number of distinct characters in the input
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0;
        bitset<128> seen;   // seen[c] stores whether char c has been seen
        for (int r = 0; r < s.length(); ++r) {  // find the longest valid substring ending at each index r
            while (seen[s[r]]) {
                seen[s[l]] = 0; // advance l until substring is valid
                ++l;
            }
            seen[s[r]] = 1;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
