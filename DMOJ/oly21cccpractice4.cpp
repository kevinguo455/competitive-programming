#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2001, INF = 0x3f3f3f3f;

int arr[MAXN][MAXN];
int pre_min[MAXN][MAXN];
int pre_max[MAXN][MAXN];
int suf_min[MAXN][MAXN];
int suf_max[MAXN][MAXN];
int dp[MAXN+1][MAXN+1];
int dp_suf_min[MAXN+1][MAXN+1];

int R, C;

int diff(int r, int c) {
    if (c == 0) return suf_max[r][c] - suf_min[r][c];
    if (c == C) return pre_max[r][c-1] - pre_min[r][c-1];
    return max(pre_max[r][c-1] - pre_min[r][c-1], suf_max[r][c] - suf_min[r][c]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> arr[r][c];
        }
    }

    for (int r = 0; r < R; r++) {
        pre_min[r][0] = arr[r][0];
        pre_max[r][0] = arr[r][0];
        for (int c = 1; c < C; c++) {
            pre_min[r][c] = min(pre_min[r][c-1], arr[r][c]);
            pre_max[r][c] = max(pre_max[r][c-1], arr[r][c]);
        }

        suf_min[r][C-1] = arr[r][C-1];
        suf_max[r][C-1] = arr[r][C-1];
        for (int c = C-2; c >= 0; c--) {
            suf_min[r][c] = min(suf_min[r][c+1], arr[r][c]);
            suf_max[r][c] = max(suf_max[r][c+1], arr[r][c]);
        }
    }

    for (int s = 0; s <= C; s++) {
        dp[0][s] = diff(0, s);
    }

    for (int r = 1; r < R; r++) {
        for (int s = 0; s <= C; s++) {
            dp[r][s] = diff(r, s);
            for (int i = s; i <= C; i++) {
                dp[r][s] = min(dp[r][s], dp[r-1][i]);
            }
        }
    }

    int ans = INF;
    for (int c = 0; c <= C; c++) {
        ans = min(ans, dp[R-1][c]);
    }
    cout << ans << '\n';

    return 0;
}