/*
Rainfall Storage II
Key Concepts: Prefix/Suffix Max Array
https://dmoj.ca/problem/oly19practice14
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

int arr[MAXN];
int pre[MAXN];
int suf[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    pre[0] = arr[0]; suf[N-1] = arr[N-1];
    for (int i = 1; i < N; i++) pre[i] = max(pre[i-1], arr[i]);
    for (int i = N-2; i >= 0; i--) suf[i] = max(suf[i+1], arr[i]);

    long long ans = 0;
    for (int i = 0; i < N; i++) ans += max(0, (min(pre[i], suf[i]) - arr[i]));
    cout << ans << '\n';

    return 0;
}