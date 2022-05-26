/*
Leetcode 354. Russian Doll Envelopes
Key Concepts: Longest Increasing Subsequence
https://leetcode.com/problems/longest-valid-parentheses/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort envelopes by increasing height and decreasing width
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        // perform longest increasing subsequence on width
        // since envelopes are sorted by increasing height and decreasing width, it is guaranteed that
        //   an increasing subsequence by width will also be increasing in height
        vector<int> dp;
        for (vector<int>& v : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), v[1]);
            if (it == dp.end()) dp.push_back(v[1]);
            else *it = v[1];
        }
        return dp.size();
    }
};
