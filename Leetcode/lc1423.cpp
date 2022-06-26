/*
Leetcode 1423. Maximum Points You Can Obtain from Cards
Key Concepts: Sliding Window
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Observation: We will take the i leftmost cards and the k-i rightmost cards.
// Idea: Try every possible value of i using the sliding window approach.

// Time Complexity: O(N)
// Space Complexity: O(1) additional space

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // First start by taking the k leftmost cards
        int score = 0, n = cardPoints.size();
        for (int i = 0; i < k; ++i) score += cardPoints[i];
        int ans = score;
        // "Trade" a left card for a right card
        for (int idx = 1; idx <= k; ++idx) {
            score -= cardPoints[k-idx];
            score += cardPoints[n-idx];
            ans = max(ans, score);
        }
        return ans;
    }
};
