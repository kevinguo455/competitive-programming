/*
Leetcode 2264. Largest 3-Same-Digit Number in String
Key Concepts: Implementation
https://leetcode.com/problems/largest-3-same-digit-number-in-string/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char last = num[0];     // last character seen
        char cnt = 0;           // number of consecutive characters seen
        char good = NULL;       // largest 3-string of characters seen (NULL if none seen yet)
        for (char c : num) {
            if (c == last) {
                ++cnt;
                if (cnt == 3) good = max(good, c);
            } else {
                cnt = 1;
                last = c;
            }
        }
        if (good == NULL) return "";
        return string(3, good);
    }
};
