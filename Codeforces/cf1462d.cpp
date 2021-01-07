/*
Codeforces Round #690 (Div. 3) - D. Add to Neighbour and Remove
Key Concepts: Implementation
https://codeforces.com/contest/1462/problem/D
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int arr[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {
        int n; cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        // k partitions
        for (int k = n; k > 0; k--) {
            if (sum % k != 0) continue;
            int target = sum / k;
            int acc = 0;
            bool good = 1;
            for (int i = 0; i < n; i++) {
                acc += arr[i];
                if (acc == target) acc = 0;
                else if (acc > target) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                cout << n - k << "\n";
                break;
            }
        }
    }

    return 0;
}