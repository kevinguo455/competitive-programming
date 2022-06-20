/*
Leetcode 583. Delete Operation for Two Strings
Key Concepts: Longest Common Subsequence
https://leetcode.com/problems/delete-operation-for-two-strings/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Observation: We want to maximize the number of characters NOT removed.
//              The final string must be a subsequence of both initial strings,
//              so the final string should be a longest common subsequence of
//              the initial strings.

class Solution {

    // Finds the length of the longest common subsequence of strings s and t
    // Time Complexity: O(NM), where N = s.size(), M = t.size()
    // Space Complexity: O(min(N, M))
    int LCS(string s, string t) {
        if (s.size() > t.size()) return LCS(t, s);

        // Typically we would maintain a 2-dimensional DP table to solve LCS
        // Since we only need the last row of the table to find the current row,
        //   we can achieve linear space complexity by only storing two rows:
        //   the last row, and the current row.
        vector<int> dp(s.size()+1, 0);
        vector<int> last(dp);
        for (char c : t) {
            for (int i = 1; i <= s.size(); ++i) {
                if (c == s[i-1]) {
                    dp[i] = 1+last[i-1];
                } else {
                    dp[i] = max(dp[i-1], last[i]);
                }
            }
            swap(dp, last);
        }
        return last[s.size()];
    }

public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2*LCS(word1, word2);
    }
};
