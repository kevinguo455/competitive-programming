/*
COCI '07 Contest 1 #5 Srednji
Key Concepts: Ad Hoc, Prefix Sum Array
https://dmoj.ca/problem/coci07c1p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n, c; cin >> n >> c;
    int pivot, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < c) arr[i] = -1;     // less
        else if (x > c) arr[i] = 1; // greater 
        else pivot = i;             // center value
    }

    unordered_map<int, int> m;
    for (int i = pivot; i < n; i++) {
        m[arr[i]]++;                
        arr[i+1] += arr[i];
    }
    
    int ans = 0;
    for (int i = pivot; i >= 0; i--) {
        ans += m[-arr[i]];
        arr[i-1] += arr[i];
    }

    cout << ans << "\n";

    return 0;
}