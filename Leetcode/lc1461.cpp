/*
Leetcode 1461. Check If a String Contains All Binary Codes of Size K
Key Concepts: Sliding Window, Bit Operations
https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(|s| + 2^k)
    // Space Complexity: O(2^k)
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        int mask = (1<<k)-1;    // largest code of length k, it is also the number of codes of length k
        bitset<1<<20> exist;    // tracks whether a code has been seen or not
        int cur = 0;
        for (int i = 0; i < k-1; ++i) {
            cur <<= 1;          // build binary string of length k-1
            cur += (s[i] == '1');
        }
        for (int i = k-1; i < s.size(); ++i) {
            cur <<= 1;          // iterate through all substrings of length k
            cur &= mask;
            cur += (s[i] == '1');
            exist[cur] = true;
        }
                                // the total number of masks of length k is 2^k
        return exist.count() == mask+1;
    }
};
