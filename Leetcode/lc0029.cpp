/*
Leetcode 29. Divide Two Integers
Key Concepts: Binary Representation, Bit Operations
https://leetcode.com/problems/divide-two-integers/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    // Time Complexity: O(log^2 n)
    int divide(int dividend, int divisor) {
        ll ans = 0, a = labs(dividend), b = labs(divisor);
        while (a >= b) {
            ll i = 1, m = b;
            while (a >= m) {
                i <<= 1;
                m <<= 1;
            }
            ans |= i >> 1;
            a -= m >> 1;
        }
        return (dividend >= 0) == (divisor >= 0) ? min(ans, (ll)INT_MAX) : -ans;
    }
};
