// https://dmoj.ca/problem/ccc08s1
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

    string s; cin >> s;
    int n; cin >> n;
    string maxs = s;
    int maxn = n;

    while (s != "Waterloo") {
        cin >> s >> n;
        if (n < maxn) {
            maxs = s;
            maxn = n;
        }
    }

    cout << maxs << endl;

    return 0;
}