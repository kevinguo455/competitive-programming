// https://dmoj.ca/problem/ccc11s3
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e2+5;

int d5(int n, int r) {
    f(i,1,r){
        n /= 5;
    }
    return n;
}

int m5(int n, int r) {
    return n % (int) pow(5, r);
}

int scan(int x, int y) {
    if ((y == 0 && 1 <= x && x <= 3) || (y == 1 && x == 2)) {
        return 1;
    }
    if ((y == 1 && (x == 1 || x == 3)) || (y == 2 && x == 2)) {
        return 0;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int cases; cin >> cases;
    f(casen,0,cases){
        int m, x, y; cin >> m >> x >> y;
        int r = scan(d5(x,m), d5(y,m));
        while (r == 0) {
            m--;
            x = m5(x, m);
            y = m5(y, m);
            if (m < 1) {
                r = -1;
                break;
            }
            r = scan(d5(x,m), d5(y,m));
        }
        cout << (r == -1 ? "empty" : "crystal") << endl;
    }
    return 0;
}