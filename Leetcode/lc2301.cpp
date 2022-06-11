/*
Leetcode 2301. Match Substring After Replacement
Key Concepts: Data Structures (Set)
https://leetcode.com/problems/match-substring-after-replacement/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Idea: Maintain an array of sets, the ith set storing the characters that
    //       the ith character can map to.
    //
    // Let S = s.length(), T = sub.length(), M = mappings.length()
    // Time Complexity: O(ST log M)
    // Space Complexity: O(M)
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<set<int>> sets(128, set<int>()); // sets[c] contains m if char c can be mapped to char m
        for (vector<char> v : mappings) {
            sets[v[0]].insert(v[1]);
        }

        // try every possible substring of length T
        for (int i = 0; i+sub.length() <= s.length(); ++i) {
            bool good = 1;
            for (int j = 0; j < sub.length(); ++j) {
                if (sub[j] != s[i+j] && sets[sub[j]].find(s[i+j]) == sets[sub[j]].end()) {
                    good = 0;
                    break;
                }
            }
            if (good) return true;
        }
        return false;
    }
};
