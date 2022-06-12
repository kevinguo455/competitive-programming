/*
Leetcode 1332. Remove Palindromic Subsequences
Key Concepts: Reading the Question
https://leetcode.com/problems/remove-palindromic-subsequences/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Note that s consists of only 'a' and 'b'.
//
// A subsequence consisting of only 'a's or only 'b's is a palindrome,
//   so all the characters in s can always be removed in 2 steps:
//   First step removing all the 'a's, second step removing all the 'b's.
//
// The only way s can be removed in one step is if s is already a palindrome.
//
// Thus we return 1 if s is a palindrome and 2 otherwise.

class Solution {
    bool isPalin(string s) {
        for (int i = 0; i < s.length()/2; ++i) {
            if (s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }

public:
    int removePalindromeSub(string s) {
        return isPalin(s) ? 1 : 2;
    }
};
