/*
An Animal Contest 1 P2 - Alpaca Racing
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/aac1p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6+5; 

ll arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K, D, X; cin >> N >> K >> D >> X; X = (100-X);
    for (int i = 0; i < N; i++) cin >> arr[i];
    ll P; cin >> P;

    for (int i = 0; i < N && D >= 0; i++) {
        while (arr[i] >= P && D >= 0) {
            arr[i] *= X;
            arr[i] /= 100;
            D--;
        }
    }

    cout << (D >= 0 ? "YES" : "NO") << '\n';

    return 0;
}