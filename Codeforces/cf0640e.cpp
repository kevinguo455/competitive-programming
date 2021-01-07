/*
Codeforces Round #640 (Div. 4) - E. Special Elements
https://codeforces.com/problemset/problem/1352/E
Key Concepts: Two Pointers
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))

const int MAXN = 8005;

int arr[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int l = 0, r = 1, s = arr[0] + arr[1];
            while (true) {
                if (s == arr[i]) {
                    ans++;
                    break;
                }
                if (l == n-2) break;
                if ((r == n-1 || s > arr[i]) && r-l >= 2) {
                    s -= arr[l];
                    l++;
                }
                else {
                    r++;
                    s += arr[r];
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}