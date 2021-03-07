/*
Mackenzie New Year's Challenge '17 - Problem 1: 2048
Key Concepts: Implementation
https://dmoj.ca/problem/mnyc17p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 31; 

map<int, int> vals;
int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= 20; i++) vals[1<<i] = i;
    
    int N; cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        arr[vals[x]]++;
    }
    int ans = 1;
    for (int i = 0; i+1 < MAXN; i++) {
        arr[i+1] += arr[i]/2;
        if (arr[i+1]) ans = i+1;
    }
    cout << (1 << ans) << '\n';

    return 0;
}