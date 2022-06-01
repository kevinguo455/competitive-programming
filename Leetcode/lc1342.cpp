/*
Leetcode 1342. Number of Steps to Reduce a Number to Zero
Key Concepts: Implementation
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Simulate the process in the problem
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        if (num & 1) return 1 + numberOfSteps(num-1);
        return 1 + numberOfSteps(num/2);
    }
};
