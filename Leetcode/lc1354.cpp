/*
Leetcode 1354. Construct Target Array With Multiple Sums
Key Concepts: Ad Hoc (Working Backwards), Heaps
https://leetcode.com/problems/construct-target-array-with-multiple-sums/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Idea: Simulate the process in reverse by replacing the largest element in the array.
//       Maintain the sum of the entire array, and a heap to find the largest element quickly.

// Time Complexity: O(N log N)
// Space Complexity: O(N)

// Note: We guarantee a linear amount of heap operations are performed since the sum decreases quadratically.

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        
        long long sum = 0;
        for (int n : target) sum += n;

        priority_queue<int> pq(target.begin(), target.end());
        while (sum > target.size()) {
            // remove largest element
            int c = pq.top(); pq.pop();
            sum -= c;   // sum now stores sum of all other elements in the array (except the largest one)

            if (c <= sum) return false;
            c %= sum;   // remove as many copies of sum as possible (must remove at least one)

            if (c == 0 && sum != 1) return false;   // edge case when target.size() == 2
            
            // reinsert new element
            sum += c;
            pq.push(c);
        }
        return true;
    }
};
