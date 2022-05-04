/*
DMPG '15 S5 - Black and White
Key Concepts: 2D Prefix Sum Array
https://dmoj.ca/problem/dmpg15s5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+5; 

bool arr[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    for (int i = 0, x, y, w, h; i < M; i++) {
        cin >> x >> y >> w >> h;
        arr[x][y] ^= 1;
        arr[x+w][y] ^= 1;
        arr[x][y+h] ^= 1;
        arr[x+w][y+h] ^= 1;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) ans++;
            arr[i][j+1] ^= arr[i][j];
            arr[i+1][j] ^= arr[i][j];
            arr[i+1][j+1] ^= arr[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}