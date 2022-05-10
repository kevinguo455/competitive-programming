/*
Leetcode 216. Combination Sum III
Key Concepts: Bitmask
https://leetcode.com/problems/combination-sum-iii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // General Idea: Use bitmasks of 9 binary digits where the ith binary digit represents if
    //               digit i is used in the combination.

    // Converts an integer bitmask to its corresponding vector
    vector<int> combination(int n) {
        vector<int> ans;
        int idx = 1;
        while (n > 0) {
            if (n & 1) ans.push_back(idx);
            ++idx;
            n >>= 1;
        }
        return ans;
    }

    int count_set_bits(int n) {
        int ans = 0;
        while (n > 0) {
            if (n & 1) ++ans;
            n >>= 1;
        }
        return ans;
    }

    const int MAXN = 1 << 9;

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;

        // Iterate through all bitmasks
        for (int i = 0; i < MAXN; ++i) {
            if (count_set_bits(i) != k) continue;

            vector<int> comb = combination(i);
            int sum = 0;
            for (int n : comb) sum += n;
            if (sum == n) ans.push_back(comb);
        }
        
        return ans;
    }
};
