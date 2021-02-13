// https://dmoj.ca/problem/ccc10s1
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

    int n, a, b, c, q, mq1 = 0, mq2 = 0; cin >> n;
    string s, ms1 = "", ms2 = "";
    if (n == 0) return 0;
    else if (n == 1) {
        cin >> s;
        cout << s << endl;
        return 0;
    }
    f(i,0,n){
        cin >> s >> a >> b >> c;
        q = 2*a + 3*b + c;
        if (q > mq1 || (q == mq1 && s < ms1)) {
            mq2 = mq1;
            ms2 = ms1;
            mq1 = q;
            ms1 = s;
        }
        else if (q > mq2 || (q == mq2 && s < ms2)) {
            mq2 = q;
            ms2 = s;
        }
    }
    cout << ms1 << endl << ms2 << endl;
    return 0;
}