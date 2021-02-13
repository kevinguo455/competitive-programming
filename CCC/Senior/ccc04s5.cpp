/*
CCC '04 S5 - Super Plumber
Key Concepts: Dynamic Programming
https://dmoj.ca/problem/ccc04s5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 101; 

string grid[MAXN];
int rows, cols;
int dp0[MAXN];
int dp1[MAXN];

// score from moving from a to b in col
int score(int col, int a, int b) {
    if (b < a) return score(col, b, a);
    int out = 0;
    for (int i = a; i <= b; i++) {
        if (grid[i][col] == '*') return -INF;
        else if (grid[i][col] != '.') out += grid[i][col] - '0';
    }
    return out;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> rows >> cols;
    while (rows != 0) {
        for (int i = 0; i < rows; i++) {
            cin >> grid[i];
        }

        ms(dp0, -INF);
        dp0[rows-1] = 0;

        for (int i = 0; i < cols; i++) {
            ms(dp1, -INF);

            // find max score from last col to each point on this col
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < rows; k++) {
                    dp1[j] = max(dp1[j], dp0[k] + score(i, j, k));
                }
            }

            // copy array
            for (int j = 0; j < rows; j++) {
                dp0[j] = dp1[j];
            }
        }

        cout << dp0[rows-1] << "\n";

        cin >> rows >> cols;
    }

    return 0;
}