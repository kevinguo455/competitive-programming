/*
Baltic OI '05 P2 - LISP
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/btoi05p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    int rank = 0;
    char c;
    while (N--) {
        cin >> c;
        if (c == '(') rank++;
        else rank--;

        if (rank < 0) {
            cout << "0\n";
            return 0;
        }
    }
    
    for (int i = 0; i < M; i++) cout << "1\n";
    cout << rank + 1 << '\n';

    return 0;
}