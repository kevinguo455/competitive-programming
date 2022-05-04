/*
Getting Snappy
Key Concepts: Simple Math, Implementation
https://dmoj.ca/problem/tc19summerj1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int M, N, tmp; cin >> N >> M;
    while (N > M) {
        tmp = N;
        N /= 2;
    }
    if (N == M) cout << "N\n";
    else {
        if (tmp-M <= M-N) cout << tmp << '\n';
        else cout << N << '\n';
    }

    return 0;
}