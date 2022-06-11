/*
Leetcode 2300. Successful Pairs of Spells and Potions
Key Concepts: Prefix Sum Array
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

class Solution {
public:
    // Observation: If a spell and potion pair is successful, then the spell and all stronger potions
    //              will be successful too.
    // Idea: Build a suffix sum array, where cnt[i] stores the number of potions with strength at least i
    //
    // Time Complexity: O(N + M), where N is the number of spells, and M is the maximum potion strength
    // Space Complexity: O(M)
    //
    // An alternate solution involving sorting the potions and binary searching for each query
    // is possible, and has O(N log M) time complexity and O(1) space complexity.
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        // Build suffix sum array
        vector<int> cnt(MAXN, 0);
        for (int i : potions) {
            ++cnt[i];
        }
        for (int i = MAXN-2; i >= 0; --i) {
            cnt[i] += cnt[i+1];
        }

        // Query each spell
        for (int i = 0; i < spells.size(); ++i) {
            long long idx = ceil(success/(long double)spells[i]);
            if (idx >= MAXN) spells[i] = 0;
            else spells[i] = cnt[idx];
        }
        return spells;
    }
};
