// https://dmoj.ca/problem/ccc19j1
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 105; //100005

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a1, a2, a3, b1, b2, b3; cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int a = a1*3 + a2*2 + a3;
    int b = b1*3 + b2*2 + b3;
    if (a == b) cout << "T" << endl;
    else if (a < b) cout << "B" << endl;
    else cout << "A" << endl;
    return 0;
}