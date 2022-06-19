/*
Leetcode 2310. Sum of Numbers With Units Digit K
Key Concepts: Simple Math
https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Observation 1: The only case where zero numbers are required is when num == 0.
// Observation 2: The numbers in the set are of the form 10*a + k. We can "distribute"
//                the multiples of 10 arbitrarily among the numbers in the set;
//                we only need to keep track of how many times we include k.
//                We stop when we need a multiple of 10 to reach num.

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (k == 0) return -1;

        int ans = 1;
        while (num % 10 != k) {
            num -= k;
            ++ans;
            if (num < 0) return -1;
        }
        return ans;
    }
};
