/*
Glenforest Spring Open '15 Junior 4 - Marathon
Key Concepts: Prefix Sum Array
https://dmoj.ca/problem/gfssoc2j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        cout << arr[a-1] - arr[b] + arr[N] << '\n';
    }

    return 0;
}