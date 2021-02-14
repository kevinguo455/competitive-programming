/*
Largest Permutation
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/largeperm
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e1+5;

int idx[MAXN];
int val[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        idx[x] = i;
        val[i] = x;
    }

    for (int i = 0; i < N; i++) {
        if (K > 0 && val[i] != N-i) {
            swap(val[i], val[idx[N-i]]);
            swap(idx[N-i], idx[val[idx[N-i]]]);
            K--;
        }
        cout << val[i] << ' ';
    }

    cout << '\n';

    return 0;
}