/*
Leetcode 647. Palindromic Substrings
Key Concepts: Implementation
https://leetcode.com/problems/palindromic-substrings/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Idea: Find the palindromes starting from the center and moving outwards
    int countSubstrings(string s) {
        int ans = 0;
        for (int center = 0; center < s.size(); ++center) {
            // odd length palindromes
            for (int radius = 0; center-radius >= 0 && center+radius < s.size(); ++radius) {
                if (s[center-radius] != s[center+radius]) break;
                ++ans;
            }
            // even length palindromes
            for (int radius = 0; center-radius >= 0 && center+radius+1 < s.size(); ++radius) {
                if (s[center-radius] != s[center+radius+1]) break;
                ++ans;
            }
        }
        return ans;
    }
};
