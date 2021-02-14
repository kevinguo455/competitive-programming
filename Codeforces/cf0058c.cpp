/*
Codeforces Beta Round #54 (Div. 2) - C. Trees
Key Concepts: Greedy Algorithms
https://codeforces.com/contest/58/problem/C
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int score[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (i*2 < N) {
            if (x-i > 0) score[x-i]++;
        }
        else {
            if (x-(N-i-1) > 0) score[x-(N-i-1)]++;
        }
    }

    int ms = 0;
    for (int i = 1; i < MAXN; i++) {
        ms = max(ms, score[i]);
    }
    cout << N - ms << '\n';

    return 0;
}