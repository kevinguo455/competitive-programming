/*
Leetcode 1723. Find Minimum Time to Finish All Jobs
Key Concepts: Recursion
https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Brute force recursion, try assigning each job to each worker
// Time Complexity: O(N^K), where N = cookies.size() and k is number of children
// Space Complexity: O(N+K)

class Solution {
    int ans;   // stores the best answer found so far

    // Recursively solve
    //   jobs     is input array of jobs
    //   time     stores the current working time of each worker
    //   k        is number of workers
    //   cur      is the current job being distributed
    void solve(vector<int>& jobs, vector<int>& time, int k, int cur) {
        if (cur == jobs.size()) {
            // Done distributing jobs
            int score = 0;
            for (int i : time) score = max(score, i);
            ans = min(ans, score);
            return;
        }
        // Try distribute jobs[cur] to each worker
        for (int i = 0; i < k; ++i) {
            time[i] += jobs[cur];
            if (time[i] < ans) solve(jobs, time, k, cur+1);
            time[i] -= jobs[cur];
        }
    }

public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end());
        vector<int> time(k, 0);
        int idx = 0;
        for (int j : jobs) {
            time[idx] += j;
            ++idx;
            if (idx == k) idx = 0;
        }
        ans = 0;
        for (int i : time) ans = max(ans, i);

        time.assign(k, 0);
        solve(jobs, time, k, 0);
        return ans;
    }
};
