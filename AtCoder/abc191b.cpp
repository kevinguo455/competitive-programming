/*

Key Concepts: 
https://dmoj.ca/problem/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, X; cin >> N >> X;
    int v;
    while (N--) {
        cin >> v;
        if (v != X) cout << v << ' ';
    }
    cout << '\n';

    return 0;
}