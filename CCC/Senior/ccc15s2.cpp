/*
CCC '15 S2 - Jerseys
Key Concepts: Implementation, Greedy Algorithms
https://dmoj.ca/problem/ccc15s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

map<char, int> m;
int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    m['S'] = 1;
    m['M'] = 2;
    m['L'] = 3;

    int N, M; cin >> N >> M;
    char c;
    for (int i = 1; i <= N; i++) {
        cin >> c;
        arr[i] = m[c];
    }
    int x, ans = 0;
    while (M--) {
        cin >> c >> x;
        if (arr[x] >= m[c]) {
            arr[x] = -1;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}