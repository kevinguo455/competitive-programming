/*
Leetcode 2306. Naming a Company
Key Concepts: Hash Set, Dynamic Programming, Ad Hoc
https://leetcode.com/problems/naming-a-company/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXM = 26;

class Solution {
public:
    // Time Complexity: O(NMS), where N = ideas.length()
    //                                M = number of characters in alphabet
    //                                S = maximum length of string
    // Since M = 26 and S = 10 in this problem, the solution is O(N)
    //
    // Space Complexity: O(NS + M^2)
    long long distinctNames(vector<string>& ideas) {
        // Build hash set of strings in input to check whether a given string
        // is in the input, in O(S) time
        unordered_set<string> ss;
        for (string s : ideas) ss.insert(s);

        // score[i][j] is the number of valid strings with the first char i swapped with j
        vector<vector<ll>> score(MAXM, vector<ll>(MAXM, 0));

        // build score[i][j]
        for (string s : ideas) {
            int j = s[0] - 'a';
            for (int i = 0; i < MAXM; ++i) {
                if (i == j) continue;
                s[0] = 'a'+i;
                if (ss.find(s) == ss.end()) {
                    score[i][j]++;
                }
            }
        }

        // every string with first char i swapped j can be "paired" with a string
        // with first char j swapped with i
        ll ans = 0;
        for (int i = 0; i < MAXM; ++i) {
            for (int j = 0; j < MAXM; ++j) {
                ans += (ll)score[i][j] * score[j][i];
            }
        }
        return ans;
    }
};
