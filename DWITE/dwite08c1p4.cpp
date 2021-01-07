/*
DWITE '08 R1 #4 - What is this Roman Numeral
Key Concepts: Implementation
https://dmoj.ca/problem/dwite08c1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    unordered_map<char, int> val = {{'I', 1}, 
                            {'V', 5}, 
                            {'X', 10}, 
                            {'L', 50},  
                            {'C', 100}, 
                            {'D', 500}, 
                            {'M', 1000}};

    for (int cases = 0; cases < 5; cases++) {
        
        string s; cin >> s;
        int ans = 0;
        int mv = 0;
        
        for (int i = s.length()-1; i >= 0; i--) {
            int v = val[s[i]];
            if (v < mv) ans -= v;
            else ans += v;
            mv = max(mv, v);
        }

        cout << ans << "\n";

    }

    return 0;
}