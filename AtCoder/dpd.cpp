// https://dmoj.ca/problem/dpd
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5;

ll val[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, w, iw, iv; cin >> n >> w;
    f(i,0,n){
        cin >> iw >> iv;
        fr(j,w,iw-1){
            val[j] = max(val[j], val[j-iw] + iv); // either put item in or not
        }
    }
    cout << val[w] << endl;
    return 0;
}