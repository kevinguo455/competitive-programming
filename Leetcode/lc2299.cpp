/*
Leetcode 2299. Strong Password Checker II
Key Concepts: Implementation
https://leetcode.com/problems/strong-password-checker-ii/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Directly check each condition listed in the question
    bool strongPasswordCheckerII(string password) {
        if (password.length() < 8) return false;
        
        bool lower = 0, upper = 0, digit = 0, special = 0;
        for (char c : password) {
            if (c >= 'a' && c <= 'z') lower = 1;
            if (c >= 'A' && c <= 'Z') upper = 1;
            if (c >= '0' && c <= '9') digit = 1;
            string s ="!@#$%^&*()-+";
            if (s.find(c) != string::npos) special = 1;
        }
        if (!lower || !upper || !digit || !special) return false;

        for (int i = 0; i+1 < password.size(); ++i) {
            if (password[i] == password[i+1]) return false;
        }

        return true;
    }
};
