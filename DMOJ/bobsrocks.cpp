#include <bits/stdc++.h>
using namespace std;

const int MAXA = 51; 

int arr[MAXA];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x; cin >> n;
    while (n--) {
        cin >> x;
        arr[x]++;
    }

    int ans = 0, maxv = 0;
    for (int i = 0; i < MAXA; i++) {
        arr[i] *= i;
        if (arr[i] > maxv) {
            maxv = arr[i];
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}