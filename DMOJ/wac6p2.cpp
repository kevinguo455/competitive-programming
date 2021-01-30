/*
Wesley's Anger Contest 6 Problem 2 - Cheap Christmas Lights
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/wac6p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5; 

bitset<MAXN> b;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int x;
    
    // flip all bits to 1
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x) b[i] = 1;
    }

    if (b.count() == 0) {
        cout << "0\n";
        return 0;
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> x;
        b[x] = !b[x];
        if (b.count() <= i) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << b.count() << "\n";

    return 0;
}