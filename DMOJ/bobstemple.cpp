/*
Bob's Temple
Key Concepts: Implementation
https://dmoj.ca/problem/bobstemple
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 5e5+5; 

int freq[MAXV];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int v, mv = 0;

    while (N--) {
        cin >> v;
        freq[v]++;
        mv = max(mv, v);
    }

    for (int i = 1; i <= mv; i++) {
        cout << i << " ";
    }

    for (int i = mv; i >= 1; i--) {
        while (freq[i] > 1) {
            cout << i << " ";
            freq[i]--;
        }
    }

    cout << "\n";

    return 0;
}