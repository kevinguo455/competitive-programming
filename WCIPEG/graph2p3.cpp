/*
Trees
Key Concepts: Graph Theory (Trees)
https://dmoj.ca/problem/graph1p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int e = 0, x;
    for (int i = 0; i < n*n; i++) {
        cin >> x;
        e += x;
    }
    cout << (e/2)-n+1 << "\n";

    return 0;
}