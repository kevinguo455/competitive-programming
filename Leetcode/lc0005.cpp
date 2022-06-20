/*
Leetcode 5. Longest Palindromic Substring
Key Concepts: Implementation
https://leetcode.com/problems/longest-palindromic-substring/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Try every index i in s, and find the longest possible palindrome
//       centered at i.

class Solution {
public:
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    string longestPalindrome(string s) {
        // track the longest palindrome found so far
        int best = 0;
        string ans;
        for (int i = 0, j; i < s.length(); ++i) {
            // odd palindrome
            j = 0;
            while (i+j < s.length() && i-j >= 0 && s[i+j] == s[i-j]) ++j;
            if (2*j-1 > best) {
                best = 2*j-1;
                ans = s.substr(i-j+1, 2*j-1);
            }
            // even palindrome
            j = 0;
            while (i+j+1 < s.length() && i-j >= 0 && s[i+j+1] == s[i-j]) ++j;
            if (2*j > best) {
                best = 2*j;
                ans = s.substr(i-j+1, 2*j);
            }
        }
        return ans;
    }
};
