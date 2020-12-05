// https://dmoj.ca/problem/dmpg19b6
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 5300; 

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int f, s; cin >> f >> s;
    int c1 = INF, c2 = INF, x;
    f(i,0,s){
        cin >> x;
        if (x < c1) {
            c2 = c1;
            c1 = x;
        }
        else c2 = min(c2, x);
    }
    bool p1 = 0;
    f(i,0,f){
        bool p = 0, d;
        f(i,0,s){
            cin >> d;
            p ^= d;
        }
        if (i == 0) p1 = p;
        else {
            if (p != p1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (p1 == 1) cout << c1 + c2 << endl;
    else cout << c1 << endl;
    return 0;
}