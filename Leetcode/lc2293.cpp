/*
Leetcode 2293. Min Max Game
Key Concepts: Implementation
https://leetcode.com/problems/min-max-game/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Directly simulate the process in the question

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> v(nums);
        while (v.size() > 1) {
            for (int i = 0; i < v.size()/2; ++i) {
                if (i % 2 == 0) v[i] = min(v[2*i], v[2*i+1]);
                else v[i] = max(v[2*i], v[2*i+1]);
            }
            v.resize(v.size()/2);
        }
        return v[0];
    }
};
