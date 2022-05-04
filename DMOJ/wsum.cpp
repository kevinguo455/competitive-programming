/*
William and Summation
Key Concepts: Maximum Subarray Sum
https://dmoj.ca/problem/wsum
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] *= (N-i);    // Sum of prefix sums = triangle sums
        tot += arr[i];
    }

    // Maximum subarray sum
    ll best = -1E18, curr = -1E18;
    for (int i = 0; i < N; i++) {
        curr += arr[i];
        curr = max(curr, (ll)arr[i]);
        best = max(best, curr);
    }
    
    cout << tot - 2*best << '\n';

    return 0;
}