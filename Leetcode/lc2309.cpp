/*
Leetcode 2309. Greatest English Letter in Upper and Lower Case
Key Concepts: Implementation
https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;

class Solution {
public:
    string greatestLetter(string s) {
        // Iterate through s, and track if each lowercase and uppercase letter is seen
        vector<bool> lower(MAXN, 0), upper(MAXN, 0);
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                lower[c-'a'] = 1;
            }
            if (c >= 'A' && c <= 'Z') {
                upper[c-'A'] = 1;
            }
        }
        // Iterate backwards through the letters
        for (int i = MAXN-1; i >= 0; --i) {
            // Stop if both lowercase and uppercase is seen
            if (lower[i] == 1 && upper[i] == 1) {
                return string{(char)(i+'A')};
            }
        }
        // No letter has both lowercase and uppercase in the string
        return "";
    }
};
