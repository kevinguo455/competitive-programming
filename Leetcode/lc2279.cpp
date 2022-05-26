/*
Leetcode 2279. Maximum Bags With Full Capacity of Rocks
Key Concepts: Greedy Algorithms
https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Greedily fill up the bags that require the least rocks
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); ++i) {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for (int n : capacity) {
            if (additionalRocks < n) break;
            additionalRocks -= n;
            ++ans;
        }
        return ans;
    }
};
