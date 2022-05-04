/*
Leetcode 905. Sort Array By Parity
Key Concepts: Implementation
https://leetcode.com/problems/sort-array-by-parity/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)

vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> res, odd;
    for (int i : nums) {
        if (i & 1) odd.push_back(i);
        else res.push_back(i);
    }
    for (int i : odd) {
        res.push_back(i);
    }
    return res;
}
