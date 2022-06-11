/*
Leetcode 2302. Count Subarrays With Score Less Than K
Key Concepts: Two Pointers, Prefix Sum Array
https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Observation 1: Consider every starting left index. Let r be the first index such that
//                the score of [l, r] is not less than k. Then for all e in [l, r), the
//                subarray [l, e] has score less than k.
// Observation 2: As l increases, r is nondecreasing.
// Idea: Use two pointers to find r for each l in linear time, and use a prefix sum array
//       to calculate subarray sums in constant time.
//
// Time Complexity: O(N), where N = nums.size()
// Space Complexity: O(N)
//
// Instead of finding r using two pointers and a prefix sum array, an alternative solution
// is to use binary search to find the first r for each l.
// This solution has time complexity O(N log N) and space complexity O(1)

class Solution {
    // get the sum of the subarray [l, r]
    inline ll query(vector<ll>& psa, int l, int r) {
        if (l == 0) return psa[r];
        return psa[r]-psa[l-1];
    }

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // build psa
        vector<ll> psa(nums.size(), 0);
        psa[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            psa[i] = psa[i-1] + nums[i];
        }

        // perform two pointers
        int r = 0;
        ll ans = 0;
        for (int l = 0; l < nums.size(); ++l) {
            while (r < nums.size() && query(psa, l, r) * (r+1-l) < k) {
                ++r;
            }
            ans += r-l;
        }
        return ans;
        
    }
};
