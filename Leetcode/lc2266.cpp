/*
Leetcode 2266. Count Number of Texts
Key Concepts: Memoization, Simple Math (counting permutations)
https://leetcode.com/problems/count-number-of-texts/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5, MOD = 1e9+7;

int dp[MAXN];

inline int add(int a, int b) {
    return ((ll)a+(ll)b) % MOD;
}

inline int mul(int a, int b) {
    return ((ll)a*(ll)b) % MOD;
}

class Solution {
public:

    // Calculates the possible number of messages sent for a message consisting solely of freq occurences of digit
    int ways(char digit, int freq) {
        int rep = 3;
        if (digit == '7' || digit == '9') rep = 4;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        // recurrence relation: dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + (dp[i-4] if digit is 7 or 9)
        for (int i = 1; i <= freq; ++i) {
            for (int j = max(0, i-rep); j < i; ++j) {
                dp[i] = add(dp[i], dp[j]);
            }
        }
        
        return dp[freq];
    }

    int countTexts(string pressedKeys) {
        char last = pressedKeys[0];     // last character seen
        int freq = 0;                   // number of consecutive characters seen     
        int ans = 1;

        // break the string into sequences of contiguous characters
        for (char c : pressedKeys) {
            if (c == last) ++freq;
            else {
                ans = mul(ans, ways(last, freq));
                last = c;
                freq = 1;
            }
        }
        return mul(ans, ways(last, freq));
    }
};
