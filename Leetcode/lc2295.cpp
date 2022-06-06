/*
Leetcode 2295. Replace Elements in an Array
Key Concepts: Map
https://leetcode.com/problems/replace-elements-in-an-array/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Take advantage of the facts that nums contains distinct integers and
//       each operation transforms an existing integer to a new one.
//       Use a map to track the index where each integer is.

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;             // initialize indices
        }
        for (vector<int> op : operations) {
            nums[m[op[0]]] = op[1];     // modify element with value op[0] to have value op[1]
            m[op[1]] = m[op[0]];        // update index
        }
        return nums;
    }
};
