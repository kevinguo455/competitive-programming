/*
Leetcode 1859. Sorting the Sentence
Key Concepts: Strings
https://leetcode.com/problems/sorting-the-sentence/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(100);    // Stores the words in the answer in proper order
        stringstream ss(s);
        string word;
        int max_index = -1;
        // Iterate through the given string, word by word
        while (ss >> word) {
            // Place the word in the proper spot according to the number
            int index = word[word.length()-1]-'1';
            ans[index] = word.substr(0, word.length()-1);
            max_index = max(max_index, index);
        }
        // Construct the answer string
        string ret = ans[0];
        for (int i = 1; i <= max_index; ++i) {
            ret += " " + ans[i];
        }
        return ret;
    }
};
