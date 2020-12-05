// https://dmoj.ca/problem/fibonacci2
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

void cm(ll a[2][2], ll b[2][2]) {
    f(i,0,2){
        f(j,0,2){
            a[i][j] = b[i][j];
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
    cm(a,res);
}

void pm(ll a[2][2], ull p) {
    ll res[2][2];
    id(res);
    while (p > 0) {
        if (p % 2 == 1) {
            mm(res, a);
        }
        mm(a, a);
        p = p >> 1;
    }
    cm(a,res);
}

void spm(ll a[2][2], string p) {
    ll tmp[2][2];
    ll res[2][2];
    id(res);
    fr(d, p.size()-1, -1){
        cm(tmp,a);
        if (p[d] == '2') pm(tmp,2);
        else if (p[d] == '3') pm(tmp,3);
        else if (p[d] == '4') pm(tmp,4);
        else if (p[d] == '5') pm(tmp,5);
        else if (p[d] == '6') pm(tmp,6);
        else if (p[d] == '7') pm(tmp,7);
        else if (p[d] == '8') pm(tmp,8);
        else if (p[d] == '9') pm(tmp,9);
        
        if (p[d] != '0') mm(res,tmp);
        pm(a,10);
    }
    cm(a,res);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    string n; cin >> n;
    ll fm[2][2] = {1, 1, 1, 0};
    spm(fm, n);
    cout << fm[0][1] << endl;
    return 0;
}