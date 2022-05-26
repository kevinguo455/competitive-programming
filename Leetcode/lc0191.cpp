/*
Leetcode 191. Number of 1 Bits
Key Concepts: Bit Operations
https://leetcode.com/problems/number-of-1-bits/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Idea: Repeatedly bitshift n to the right, and count the number of times the rightmost bit is 1.
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            if (n & 1) ++ans;
            n >>= 1;
        }
        return ans;
    }
};
