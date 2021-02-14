/*
Codeforces Round #111 (Div. 2) - C. Find Pair
Key Concepts: Implementation
https://codeforces.com/contest/160/problem/C
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+5; 

int arr[MAXN];
map<int, int> freq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; ll K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    sort(arr, arr + N);

    for (pair<int, int> p : freq) {
        if (K > (ll) p.second * N) {
            K -= (ll) p.second * N;
        }
        else {
            for (int i = 0; i < N; i++) {
                K -= p.second;
                if (K <= 0) {
                    cout << p.first << ' ' << arr[i] << '\n';
                    return 0;
                }
            }
        }
    }
}