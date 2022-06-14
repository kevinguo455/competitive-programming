/*
Leetcode 2303. Calculate Amount Paid in Taxes
Key Concepts: Implementation
https://leetcode.com/problems/calculate-amount-paid-in-taxes/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int last = 0;
        double ans = 0;
        for (vector<int> v : brackets) {
            v[0] = min(v[0], income);   // (v[0] - last) is the amount of money taxed at this bracket
            ans += (v[0] - last) * ((double) v[1])/100.0;
            last = v[0];
        }
        return ans;
    }
};
