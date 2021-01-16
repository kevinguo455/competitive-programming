/*
Vincent Massey SS - 2014 Senior Contest #1: Lil' Jami
Key Concepts: Data Structures (Prefix Sum Array)
https://dmoj.ca/problem/liljami
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n, k; cin >> n >> k;
    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        arr[x+1]++;
    }

    // build prefix sum array
    for (int i = 0; i < n; i++) {
        arr[i+1] += arr[i];
    }

    // answer querires
    int q; cin >> q;
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << arr[r+1] - arr[l] << "\n";
    }

    return 0;
}