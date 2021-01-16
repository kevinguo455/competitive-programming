/*
DWITE '09 R1 #3 - That Missing Number
Key Concepts: Implementation
https://dmoj.ca/problem/dwite09c1p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))

const int MAXN = 101; 

bool arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int cases = 0; cases < 5; cases++) {
        int n, x; cin >> n;
        ms(arr, 0);
        for (int i = 0; i < n; i++) {
            cin >> x;
            arr[x] = 1;
        }
        for (int i = 1; i <= n+1; i++) {
            if (!arr[i]) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}