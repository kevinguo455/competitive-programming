/*
Leetcode 1209. Remove All Adjacent Duplicates in String II
Key Concepts: Data Structures (stack)
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // simulate a stack by maintaining an index in the resulting string and "popping" adjacent segments of stack k
        string ans;
        ans.resize(s.size());
        vector<short> freq(s.size(),0);
        int idx = -1;

        for (char c : s) {
            if (idx < 0 || c != ans[idx]) {
                ++idx;
                ans[idx] = c;
                freq[idx] = 1;
            } else {
                ++idx;
                ans[idx] = c;
                freq[idx] = freq[idx-1]+1;
                if (freq[idx] == k) {  // pop
                    idx -= k;
                }
            }
        }
        ans.resize(idx+1);

        return ans;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
