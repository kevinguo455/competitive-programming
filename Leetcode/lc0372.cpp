/*
Leetcode 372. Super Pow
Key Concepts: Binary Exponentiation
https://leetcode.com/problems/super-pow/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1337;

inline int mul(int a, int b) {
    return (a*b) % MOD;
}

class Solution {
public:

    // Standard implementation of binary exponentiation
    // Time Complexity: O(log p)
    int qpow(int a, int p) {
        int res = 1;
        while (p > 0) {
            if (p % 2 == 1) res = mul(res, a);
            a = mul(a, a);
            p /= 2;
        }
        return res;
    }

    // Extend implementation of binary exponentiation to decimal exponentiation
    // Time Complexity: O(|b|)
    int superPow(int a, vector<int>& b) {
        a %= MOD;
        int res = 1;
        for (int i = b.size()-1; i >= 0; --i) {
            res = mul(res, qpow(a, b[i]));
            a = qpow(a, 10);
        }
        return res;
    }
};
