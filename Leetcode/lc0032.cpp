/*
Leetcode 32. Longest Valid Parentheses
Key Concepts: Stack
https://leetcode.com/problems/longest-valid-parentheses/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;

        // top of stack is the index before the current valid parenthesis string
        stack<int> stk;
        stk.push(-1);
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // move forward the start of the current valid string
                stk.push(i);

            } else {
                // move back the start of the current valid string
                stk.pop();

                if (stk.empty()) {
                    // if there are no more open brackets, start the valid string before this close bracket
                    stk.push(i);
                } else {
                    // calculate length of current valid string
                    ans = max(ans, i-stk.top());
                }
            }
        }
        return ans;
    }
};
