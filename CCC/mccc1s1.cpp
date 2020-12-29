/*
Mock CCC '20 S1 - War
Key Concepts: Implementation
https://dmoj.ca/problem/mccc1s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

int arr[MAXN];

int main() {
    int n, x; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool war = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == arr[i]) {
            if (!war) {
                war = 1;
                ans++;
            }
        }
        else {
            war = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}