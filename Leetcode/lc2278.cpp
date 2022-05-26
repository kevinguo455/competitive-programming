/*
Leetcode 2278. Percentage of Letter in String
Key Concepts: Implementation
https://leetcode.com/problems/percentage-of-letter-in-string/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Count how many times letter occurs in s, then calculate the percentage.
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (char c : s) {
            if (c == letter) ++cnt;
        }
        return cnt * 100 / s.size();
    }
};
