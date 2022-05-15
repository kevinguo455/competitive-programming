/*
Leetcode 2275. Largest Combination With Bitwise AND Greater Than Zero
Key Concepts: Implementation
https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 24;

class Solution {
public:

    // Observation: The numbers in the optimal combination will all have at least one bit in common.
    //      For each bit, we find the amount of candidates that have that bit set.
    //      The answer is the maximum such amount.

    // Time Complexity: O(N log S)
    //   where N = candidates.length, S = max(candidates[i])
    int largestCombination(vector<int>& candidates) {
        vector<int> score(MAXN, 0);
        vector<int> masks;
        int m = 1;
        for (int i = 0; i < MAXN; ++i) {
            masks.push_back(m);
            m <<= 1;
        }
        for (int c : candidates) {
            for (int i = 1; i < MAXN; ++i) {
                if (c & masks[i]) ++score[i];
            }
        }

        int ans = 0;
        for (int i : score) ans = max(ans, i);
        return ans;
    }

};
