/*
Mock CCC '21 S3 - Lexicographically Smallest Permutation Subsequence
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/nccc8s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5; 

int N, K;
int arr[MAXN];
int last[MAXN];
bool in[MAXN];
stack<int> ans, out;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        last[arr[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        if (in[arr[i]]) continue;
        while (!ans.empty() && arr[i] <= ans.top() && last[ans.top()] >= i) {
            in[ans.top()] = 0;
            ans.pop();
        }
        ans.push(arr[i]);
        in[arr[i]] = 1;
    }

    for (int i = 0; i < K; i++) {
        out.push(ans.top()); ans.pop();
    }

    cout << out.top(); out.pop();
    for (int i = 1; i < K; i++) {
        cout << ' ' << out.top(); out.pop();
    }

    cout << '\n';

    return 0;
}