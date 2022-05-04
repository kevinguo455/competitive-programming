/*
ECOO '21 P3 - Quintessential Questions
Key Concepts: Implementation
https://dmoj.ca/problem/ecoo21p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5; 

int best[MAXN];
int prof[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i < MAXN; i++) prof[i] = -1;
    for (int i = 1, a, b, c; i <= K; i++) {
        cin >> a >> b >> c;
        if (c > best[b]) {
            best[b] = c;
            prof[b] = a;
        }
    }
    for (int i = 1; i <= N; i++) cout << prof[i] << ' ';
    cout << '\n';

    return 0;
}
