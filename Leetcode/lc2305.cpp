/*
Leetcode 2305. Fair Distribution of Cookies
Key Concepts: Recursion
https://leetcode.com/problems/fair-distribution-of-cookies/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Brute force recursion, try assigning each cookie to each child
// Time Complexity: O(N^K), where N = cookies.size() and k is number of children
// Space Complexity: O(N+K)

class Solution {
    int ans;   // stores the best answer found so far

    // Recursively solve
    //   cookies  is input array of cookie bags
    //   distr    stores the number of cookies each kid has
    //   k        is number of kids
    //   cur      is the current bag of cookies being distributed
    void solve(vector<int>& cookies, vector<int>& distr, int k, int cur) {
        if (cur == cookies.size()) {
            // Done distributing cookies
            int score = 0;
            for (int i : distr) score = max(score, i);
            ans = min(ans, score);
            return;
        }
        // Try distribute cookies[cur] to each kid
        for (int i = 0; i < k; ++i) {
            distr[i] += cookies[cur];
            solve(cookies, distr, k, cur+1);
            distr[i] -= cookies[cur];
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        ans = 0x3f3f3f3f;
        vector<int> distr(k, 0);
        solve(cookies, distr, k, 0);
        return ans;
    }
};
