/*
Leetcode 50. Pow(x, n)
Key Concepts: Binary Exponentiation
https://leetcode.com/problems/powx-n/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Time Complexity: O(log |n|)
    double myPow(double x, int n) {
        // Handle case where n is negative
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        // Standard implementation of binary exponentiation
        double res = 1;
        while (n > 0) {
            if (n % 2 == 1) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};
