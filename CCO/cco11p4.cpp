/*
CCO '11 P4 - Reorganization
Key Concepts: Greedy Algorithms, Implementation (multiset)
https://dmoj.ca/problem/cco11p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    multiset<int> s;
    int n, x; cin >> n >> x;
    s.insert(x);
    s.insert(x);

    for (int i = 1; i < n; i++) {
        cin >> x;
        multiset<int>::iterator it = s.lower_bound(x);
        if (it == s.begin()) {
            cout << "NO\n";
            return 0;
        }
        s.erase(prev(it));
        s.insert(x);
        s.insert(x);
    }

    cout << "YES\n";
    return 0;
}