/*
Mock CCC '21 S2/J5 - Pepper and Celery Pizza
Key Concepts: Implementation :(
https://dmoj.ca/problem/https://www.hackerrank.com/contests/mss-csec-mock-2021-senior/challenges/csec-2021-mock-other
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1005; 

int grid[MAXN][MAXN];
int N;

bool inr(int r, int c) {
    return (r >= 0 && c >= 0 && r < N && c < N);
}

bool free(int r, int c) {
    if (!inr(r, c)) return 0;
    return (grid[r][c] == 0);
}

int c1h(int r, int cl) {
    int ans = 0;
    bool a = free(r, cl-2);
    bool b = free(r, cl-1);
    bool c = free(r, cl);
    bool d = free(r, cl+1);
    bool e = free(r, cl+2);
    if (a && b && c) ans++;
    if (b && c && d) ans++;
    if (c && d && e) ans++;
    return ans;
}

// from left
int c2h(int r, int cl) {
    int ans = 0;
    bool a = free(r, cl-2);
    bool b = free(r, cl-1);
    bool c = free(r, cl);
    bool d = free(r, cl+1);
    bool e = free(r, cl+2);
    bool f = free(r, cl+3);
    if (a && b && c) ans++;
    if (b && c && d) ans++;
    if (c && d && e) ans++;
    if (d && e && f) ans++;
    return ans;
}

int c1v(int r, int cl) {
    int ans = 0;
    bool a = free(r-2, cl);
    bool b = free(r-1, cl);
    bool c = free(r, cl);
    bool d = free(r+1, cl);
    bool e = free(r+2, cl);
    if (a && b && c) ans++;
    if (b && c && d) ans++;
    if (c && d && e) ans++;
    return ans;
}

// from top
int c2v(int r, int cl) {
    int ans = 0;
    bool a = free(r-2, cl);
    bool b = free(r-1, cl);
    bool c = free(r, cl);
    bool d = free(r+1, cl);
    bool e = free(r+2, cl);
    bool f = free(r+3, cl);
    if (a && b && c) ans++;
    if (b && c && d) ans++;
    if (c && d && e) ans++;
    if (d && e && f) ans++;
    return ans;
}

// topmost, leftmost
int line(int r, int c) {
    if (!free(r, c)) return 0;
    int ans = 0;
    if (free(r, c+1) && free(r, c+2)) ans++;
    if (free(r+1, c) && free(r+2, c)) ans++;
    return ans;
}   

// center
ll root(int r, int c, ll lcount) {
    if (!free(r, c)) return 0;
    ll ans = 0;
    int cc1h = c1h(r, c);
    int cc1v = c1v(r, c);
    if (free(r-1, c) && free(r-1, c+1)) {
        ans += lcount - c2h(r-1, c) - cc1h - c2v(r-1, c) - c1v(r-1, c+1);
    }
    if (free(r, c+1) && free(r+1, c+1)) {
        ans += lcount - c2h(r, c) - c1h(r+1, c+1) - c2v(r, c+1) - cc1v;
    }
    if (free(r+1, c) && free(r+1, c-1)) {
        ans += lcount - c2h(r+1, c-1) - cc1h - c2v(r, c) - c1v(r+1, c-1);
    }
    if (free(r, c-1) && free(r-1, c-1)) {
        ans += lcount - c2h(r, c-1) - c1h(r-1, c-1) - c2v(r-1, c-1) - cc1v;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if (c == 'X') grid[i][j] = 1;
        }
    }

    ll pcount = 0, ccount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ccount += line(i, j);
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += root(i, j, ccount);
        }
    }

    cout << ans << "\n";

    return 0;
}