// https://dmoj.ca/problem/fibonacci
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 105; //100005

void id(ll a[2][2]) {
    f(i,0,2){
        f(j,0,2){
            if (i == j) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
}

void dm(ll a[2][2]) {
    f(i,0,2){
        f(j,0,2){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void mm(ll a[2][2], ll b[2][2]) {
    ll res[2][2];
    f(i,0,2){
        f(j,0,2){
            res[i][j] = 0;
            f(k,0,2){
                res[i][j] = (res[i][j] + (a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
            }
        }
    }
    f(i,0,2){
        f(j,0,2){
            a[i][j] = res[i][j];
        }
    }
}

void mp(ll a[2][2], ull p) {
    ll res[2][2];
    id(res);
    while (p > 0) {
        if (p % 2 == 1) {
            mm(res, a);
        }
        mm(a, a);
        p = p >> 1;
    }
    f(i,0,2){
        f(j,0,2){
            a[i][j] = res[i][j];
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ull n; cin >> n;
    ll fm[2][2] = {1, 1, 1, 0};
    mp(fm, n-1);
    cout << fm[0][0] << endl;
    return 0;
}