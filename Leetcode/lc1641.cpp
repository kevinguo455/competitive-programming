/*
Leetcode 1641. Count Sorted Vowel Strings
Key Concepts: Combinatorics (Stars and Bars)
https://leetcode.com/problems/count-sorted-vowel-strings/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Idea: Out of (n+4) possible items, choose n to be letters and the other 4
    //       to be "transitions" from one vowel to the next.

    // e.g. For n = 2, let * denote a letter and let | denote a transition.
    //      Then *||*|| denotes the vowel string "ai".

    int countVowelStrings(int n) {
        // (n+4) choose 4
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }
};
