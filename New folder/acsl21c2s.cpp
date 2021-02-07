/*
ACSL 2020-2021 Contest 2, Senior Division - Lex Strings
Key Concepts: String Algorithms, Implementation
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

// checks whether char is valid (0-9, A-Z, a-z) or not
bool isValid(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

string rearrangedString(string s) {
    
    // build frequency map
    unordered_map<char, int> frequency_map;
    for (char c : s) {
        if (isValid(c)) {
            frequency_map[c]++;
        }
    }
    
    // build frequency array
    vector<char> frequency_array[MAXN];
    for (pair<char, int> entry : frequency_map) {
        frequency_array[entry.second].push_back(entry.first);
    }

    // build output string
    string out = "";
    bool first = 1, parity = 1; // 1 = ascending, 0 = descending
    for (int i = MAXN-1; i >= 1; i--) {
        if (frequency_array[i].size() == 0) continue;
        
        if (parity) sort(frequency_array[i].begin(), frequency_array[i].end());
        else sort(frequency_array[i].begin(), frequency_array[i].end(), greater<char>());
        parity = !parity;

        if (!first) out += ',';
        first = 0;

        out += to_string(i);
        for (char c : frequency_array[i]) out += c;
    }

    return out;
}



int main() {

    while (true) {
        string s; getline(cin, s);
        cout << rearrangedString(s) << endl;
    }

    return 0;
}