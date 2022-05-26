/*
Leetcode 2280. Minimum Lines to Represent a Line Chart
Key Concepts: Simple Math (slope)
https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
    // Determines if slope of the line segments [v0, v1] and [v1, v2] are the same
    bool eq_slope(vector<int> v0, vector<int> v1, vector<int> v2) {
        return ((ll)v2[0]-v1[0])*(v1[1]-v0[1]) == ((ll)v2[1]-v1[1])*(v1[0]-v0[0]);
    }

public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        // Edge case: No lines required for one point
        if (stockPrices.size() == 1) return 0;

        // Sort points by increasing order of x-coordinate
        sort(stockPrices.begin(), stockPrices.end());

        // Number of lines required = number of times the slope changes
        int ans = 1;
        for (int i = 2; i < stockPrices.size(); ++i) {
            if (!eq_slope(stockPrices[i-2], stockPrices[i-1], stockPrices[i])) ++ans;
        }
        return ans;
    }
};
