/*
Leetcode 1048. Longest String Chain
Key Concepts: Dynamic Programming, Hash Map
https://leetcode.com/problems/longest-string-chain/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Let N be the number of words, L be the length of the longest word
    // Time Complexity: O(NlogN + N*L^2)
    // Space Complexity: O(NL)
    int longestStrChain(vector<string>& words) {

        // sort words in increasing order of length
        sort(words.begin(), words.end(), [&](string& a, string& b) {
            return a.size() < b.size();
        });

        // dp[m] is the longest string chain ending with word m
        unordered_map<string, int> dp;
        int ans = 0;

        for (string s : words) {
            int res = 1;
            for (int i = 0; i < s.size(); ++i) {
                // t is s with the ith character removed
                string t = s.substr(0, i) + s.substr(i+1);
                
                // if t exists in words, then dp[s] = max(dp[s], dp[t]+1)
                // since words has been sorted in increasing order of length,
                //   if t exists, t will be processed before s
                auto it = dp.find(t);
                if (it != dp.end()) {
                    res = min(res, it->second+1);
                }
            }
            dp[s] = res;
            ans = max(ans, res);
        }

        return ans;
    }
};
