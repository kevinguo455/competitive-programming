/*
An Animal Contest 3 P3 - Monkey Market
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/aac3p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);

    for (int i = 0; i < N/2-1; i++) cout << arr[i] << ' ' << arr[N-i-1] << ' ';
    if (N % 2) cout << arr[N/2-1] << ' ' << arr[N/2+1] << ' ' << arr[N/2] << '\n';
    else cout << arr[N/2-1] << ' ' << arr[N/2] << '\n';

    for (int i = 0; i < N/2; i++) cout << "BS";
    if (N % 2 == 1) cout << 'E';
    cout << '\n';

    return 0;
}