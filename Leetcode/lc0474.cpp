/*
Leetcode 474. Ones and Zeroes
Key Concepts: Dynamic Programming (0-1 Knapsack)
https://leetcode.com/problems/ones-and-zeroes/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Time Complexity: O(smn), where s = strs.size();
    // Space Complexity: O(mn)

    int findMaxForm(vector<string>& strs, int m, int n) {

        // dp[i][j] stores the maximum amount of strings that can be taken containing at most i zeros and j ones
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for (string s : strs) {

            // Count the number of zeros and ones in the string s
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') ++zeros;
                else ++ones;
            }

            // Update states in reverse order to prevent overwriting ones that will be read later
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);  // Don't take: dp[i][j]
                }                                                       // Take:       dp[i-zeros][j-ones]+1
            }
        }

        return dp[m][n];
    }
};
