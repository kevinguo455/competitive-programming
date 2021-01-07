/*
Codeforces Round #690 (Div. 3) - E2. Close Tuples (hard version)
Key Concepts: 
https://codeforces.com/contest/1462/problem/E
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MOD = 1e9+7;

int arr[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {

        int n, m, k; cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}