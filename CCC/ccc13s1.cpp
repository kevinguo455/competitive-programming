// https://dmoj.ca/problem/ccc13s1
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

bool dd(int n) {
    bool d[10];
    ms(d, 0);
    while (1) {
        int x = n % 10;
        n /= 10; 
        if (d[x] == 1) return false;
        d[x] = 1;
        if (n == 0) break;
    }
    return true;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    n++;
    while (!dd(n)) n++;
    cout << n << endl;
    
    return 0;
}