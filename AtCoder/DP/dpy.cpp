/*
AtCoder Educational DP Contest Problem Y - Grid 2
Key Concepts: Dynamic Programming, Intermediate Math (binomial coeffients)
https://dmoj.ca/problem/dpy
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e3+2, MAXK = 2e5+2, MOD = 1e9+7;

inline ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

inline ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll binexp(ll n, ll p) {
    ll a = 1;
    while (p) {
        if (p & 1) a = mul(a, n);
        n = mul(n, n);
        p /= 2;
    }
    return a;
}

ll fac[MAXK];
ll inv[MAXK];

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXK; i++)
        fac[i] = mul(fac[i-1], i);

    inv[0] = 1;
    for (int i = 1; i < MAXK; i++)
        inv[i] = binexp(fac[i], MOD-2);
}

/*
Faster init()
O(MAXK) instead of O(MAXK log MOD)

ll invnum[MAXK];

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXK; i++)
        fac[i] = mul(fac[i-1], i);

    invnum[1] = 1;
    for (int i = 2; i < MAXK; i++) 
        invnum[i] = MOD - MOD/i * invnum[MOD%i] % MOD;

    inv[0] = 1;
    for (int i = 1; i < MAXK; i++)
        inv[i] = mul(inv[i-1], invnum[i]);
}
*/

inline ll c(int n, int k) {
    if (k < 0) return 0;
    if (n < k) return c(k, n);
    return mul(fac[n], mul(inv[k], inv[n-k]));
}

inline ll paths(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return c(x2-x1+y2-y1, y2-y1);
}

struct Point {
    int x, y;
    ll p;
    bool operator<(const Point &p) {
        return x+y < p.x+p.y;
    }
};

int H, W, N;
Point arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();

    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].x--;
        arr[i].y--;
    }
    arr[N].x = H-1;
    arr[N].y = W-1;
    sort(arr, arr + N);

    for (int i = 0; i <= N; i++) {
        arr[i].p = paths(0, 0, arr[i].x, arr[i].y);
        for (int j = 0; j < i; j++) {
            arr[i].p = sub(arr[i].p, mul(arr[j].p, paths(arr[j].x, arr[j].y, arr[i].x, arr[i].y)));
        }
    }

    cout << arr[N].p << '\n';

    return 0;
}