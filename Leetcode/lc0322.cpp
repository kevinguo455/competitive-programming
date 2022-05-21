/*
Leetcode 322. Coin Change
Key Concepts: Unbounded Knapsack
https://leetcode.com/problems/coin-change/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(NW), where N = coins.length, W = amount
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
