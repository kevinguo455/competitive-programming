// https://dmoj.ca/problem/rgpc18p3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, t, l, a, b, x; cin >> n >> t;
    vi d(n+1);
    f(i,0,t) {
        cin >> a >> b >> x;
        d[a-1] += x;
        d[b] -= x;
    }
    d.pop_back();
    f(i,1,n) {
        d[i] += d[i-1];
    }
    cin >> l;
    int maxl = 0, s = 0, left = 0, right = 0;
    while (true) {
        if (s <= l) {
            if (right >= n) {
                maxl = max(maxl, right-left-1);
                break;
            }
            s += d[right];
            right++;
        }
        else {
            s -= d[left];
            maxl = max(maxl, right-left-1);
            left++;
        }
    }
    cout << maxl << endl;
    return 0;
}