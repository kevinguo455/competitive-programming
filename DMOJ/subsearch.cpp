/*
Subarray Search
Key Concepts: Implementation
https://dmoj.ca/problem/subsearch
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5, MOD = 1e9+7; 

int arr[MAXN], freq[MAXN], last; ll sum;
int N, F; ll S;

ll mul(ll a, ll b) {
    return (a%MOD)*(b%MOD)%MOD;
}

bool good() {
    return freq[last] <= F;
}

bool great() {
    return sum <= S;
}

bool great_good() {
    return good() && great();
}

ll sliding_window(function<bool()> condition) {
    ll ans = 0;
    int l = 0, r = 0;
    sum = arr[0];
    memset(freq, 0, sizeof freq);
    freq[arr[0]]++;
    last = arr[0];

    while (r != N) {
        if (condition()) {
            r++;
            ans += r-l;
            sum += arr[r];
            freq[arr[r]]++;
            last = arr[r];
        }
        else {
            sum -= arr[l];
            freq[arr[l]]--;
            l++;
        }
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> F >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << mul(mul(sliding_window(good), sliding_window(great)), sliding_window(great_good)) << '\n';

    return 0;
}