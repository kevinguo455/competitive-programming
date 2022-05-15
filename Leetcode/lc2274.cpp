/*
Leetcode 2274. Maximum Consecutive Floors Without Special Floors
Key Concepts: Implementation
https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // The "boundary floors" are the special floors, bottom-1, and top+1.
    // Sort the "boundary floors" then find the largest gap between two boundary floors.
    // Time Complexity: O(n log n)
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        vector<int> v(special);
        v.push_back(bottom-1);
        v.push_back(top+1);
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 1; i < v.size(); ++i) {
            ans = max(ans, v[i]-v[i-1]-1);
        }
        return ans;
    }

};
