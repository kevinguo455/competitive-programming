/*
CCC '10 S3 - Firehose
Key Concepts: Binary Search, Implementation
https://dmoj.ca/problem/ccc10s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000; 

vector<int> v;
int N, K;

int ceildiv(int n, int k) {
    int r = n/k;
    if (k*r == n) return r;
    return r+1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    v.resize(2*N);
    for (int i = 0; i < N; i++) cin >> v[i], v[i+N] = v[i] + MAXN;
    sort(v.begin(), v.end());
    cin >> K;

    if (K >= N) {
        cout << 0 << '\n';
        return 0;
    }

    int l = 0, r = MAXN, m;
    while (l != r) {
        m = (l+r)/2;

        bool works = 0;
        for (int s = 0; s < N; s++) {
            int k = K;
            int idx = v[s];
            for (int i = s; i < s+N; i++) {
                if (v[i] - idx > m) {
                    k--;
                    idx = v[i];
                }
            }
            if (k > 0) {
                works = 1;
                break;
            }
        }

        if (works) r = m;
        else l = m+1;
    }
    cout << ceildiv(l, 2) << '\n';

    return 0;
}