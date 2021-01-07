/*
Codeforces Round #690 (Div. 3) - A. Favorite Sequence
Key Concepts: Implementation
https://codeforces.com/contest/1462/problem/A
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

int arr[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {
        int l; cin >> l;
        for (int i = 0; i < l; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < (l+1)/2; i++) {
            cout << arr[i] << " ";
            if (i != l/2 || l % 2 == 0) cout << arr[l-i-1] << " ";
        }
        cout << "\n";
    }

    return 0;
}