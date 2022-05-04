/*
CCC '22 S3 - Good Samples
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/ccc22s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6+5;

ll N, M, K;
int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;

    // too few or too many samples
    if (N > K || N*M - ((M-1)*M)/2 < K) {
        cout << "-1\n";
        return 0;
    }

    K -= N;

    for (ll i = 1; i <= N; ++i) {
        ++arr[0];
        int m = min(min(i, M), K+1);
        arr[i] = arr[i-m];
        K -= m-1;
    }

    for (int i = 1; i <= N; ++i) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}