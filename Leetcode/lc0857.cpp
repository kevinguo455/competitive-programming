/*
Leetcode 857. Minimum Cost to Hire K Workers
Key Concepts: Greedy Algorithms
https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Let q[i] = quality[i], w[i] = wage[i], r[i] = wage[i] / quality[i]
    // Observation: The cost of hiring a set of S workers is max(r[i]) * sum(q[i),
    //              where the max and sum are over all workers i in S.
    // Idea: Compute r[i] for all workers, then sort workers in increasing order of r[i].
    //       Then, if we hire only workers in the range [0,j] (after sorting), then max(r[i])
    //       is r[j] since the workers are in increasing order of r[i].
    //       We can then find k workers such that sum(q[i]) is minimized using a priority queue
    //       and greedily replace workers with high q[i] with new workers of low q[i]. 
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        // compute r[i]
        vector<pair<double, int>> workers(wage.size()); // stores (r[i], q[i])
        for (int i = 0; i < wage.size(); ++i) {
            workers[i].first = (double) wage[i] / quality[i];
            workers[i].second = quality[i];
        }
        sort(workers.begin(), workers.end());

        // find sum(q[i]) over the first k workers
        int sum_quality = 0;
        priority_queue<int> chosen_quality; // store q[i]
        for (int i = 0; i < k; ++i) {
            chosen_quality.push(workers[i].second);
            sum_quality += workers[i].second;
        }

        double ans = workers[k-1].first * sum_quality;
        for (int i = k; i < wage.size(); ++i) {
            // replace the worker with highest q[i] with this current worker
            chosen_quality.push(workers[i].second);
            sum_quality += workers[i].second - chosen_quality.top();
            chosen_quality.pop();
            // recalculate max(r[i]) * sum(q[i])
            ans = min(ans, workers[i].first * sum_quality);
        }
        return ans;
    }
};
