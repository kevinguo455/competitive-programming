/*
COCI '14 Contest 3 #4 Coci
Key Concepts: 2D Prefix Sum Array
https://dmoj.ca/problem/coci14c3p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
const int MAXN = 650; 

int arr[MAXN+2][MAXN+2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int n; cin >> n;
    int x, y;
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[x][y]++;
        q.push({x, y});
    }

    // build 2D PSA
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= MAXN; j++) {
            arr[i+1][j] += arr[i][j];
            arr[i][j+1] += arr[i][j];
            arr[i+1][j+1] -= arr[i][j];
        }
    }

    // find rankings
    for (int i = 0; i < n; i++) {
        x = q.front().fi;
        y = q.front().se;
        q.pop();

        // best possible
        cout << arr[MAXN][MAXN] - arr[MAXN][y] - arr[x][MAXN] + arr[x][y] + 1 << " ";
        // worst possible
        int low = n;
        if (x != 0 && y != 0) low -= arr[x-1][y-1];
        if (x == MAXN) low -= arr[0][y] - (y == 0 ? 0 : arr[0][y-1]);
        if (y == MAXN) low -= arr[x][0] - (x == 0 ? 0 : arr[x-1][0]);
        cout << low << "\n";
    }


    return 0;
}