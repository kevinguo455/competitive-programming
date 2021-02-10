/*
CCO '03 P4 - Constrained Permutations
Key Concepts: Brute Force
https://dmoj.ca/problem/cco03p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Rule{int a, b;};

vector<Rule> v;

bool verify(int* arr, int N) {
    for (Rule r : v) {
        bool first = 0;
        bool good = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == r.a) first = 1;
            if (arr[i] == r.b && first) {
                good = 1;
                break;
            }
        }
        if (!good) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;

    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    int ans = 0;

    int arr[N];
    iota(arr, arr+N, 1);
    do {
        if (verify(arr, N)) ans++;
    }
    while (next_permutation(arr, arr+N));

    cout << ans << '\n';

    return 0;
}