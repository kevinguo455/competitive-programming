/*
Back To School '18: Letter Frequency
Key Concepts: Prefix Sum Array
https://dmoj.ca/problem/bts18p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

int arr[MAXN][26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // prefix sums
    string s; getline(cin, s);
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != ' ') arr[i+1][s[i]-'a']++;
        
        for (int j = 0; j < 26; j++) {
            arr[i+2][j] = arr[i+1][j];
        }
    }

    // answer queries
    //cin.ignore();
    int q; cin >> q;
    int l, r;
    char c;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> c;
        cout << arr[r][c-'a'] - arr[l-1][c-'a'] << "\n";
    }

    return 0;
}