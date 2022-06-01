/*
Leetcode 41. First Missing Positive
Key Concepts: XOR of Consecutive Integers
https://leetcode.com/problems/first-missing-positive/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Fact: If n === 3 (mod 4), then 1 XOR 2 XOR ... XOR n-1 XOR n = 0
    // Idea: XOR all the elements in nums, adding elements until n === 3 (mod 4)
    //       Then, the missing number is the result of the XORs.
    // Time Complexity:  O(n)
    // Space Complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        for (int i = nums.size()+1; i < (nums.size()/4+1)*4; ++i) ans ^= i;
        return ans;
    }
};
