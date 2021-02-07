/*
Favorite Numbers
Key Concepts: Data Structures (set, map)
https://dmoj.ca/problem/favnumber
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    set<int> s;
    unordered_map<int, int> freq;
    int n, q, x; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
        freq[x]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x;
        int y = *s.lower_bound(x);
        cout << y << " " << freq[y] << "\n";
    }

    return 0;
}