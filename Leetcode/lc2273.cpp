/*
Leetcode 2273. Find Resultant Array After Removing Anagrams
Key Concepts: Implementation
https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;

class Solution {
public:

    // Check if strings a and b are anagrams by comparing letter frequencies
    bool is_anagram(string a, string b) {
        vector<int> ac(MAXN, 0), bc(MAXN, 0);
        for (char c : a) ac[c-'a']++;
        for (char c : b) bc[c-'a']++;
        for (int i = 0; i < MAXN; ++i) {
            if (ac[i] != bc[i]) return 0;
        }
        return 1;
    }

    // Naively simulating the process described in the problem is fast enough to pass.
    // Time Complexity: O(n^2)
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res(words);
        bool done = 0;
        while (!done) {
            done = 1;
            for (int i = 1; i < res.size(); ++i) {
                if (is_anagram(res[i], res[i-1])) {
                    res.erase(res.begin()+i);
                    done = 0;
                    break;
                }
            }
        }
        return res;
    }  

};
