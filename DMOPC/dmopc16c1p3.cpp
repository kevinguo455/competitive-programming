// https://dmoj.ca/problem/dmopc16c1p3
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e4+5; 

double min3(double a, double b, double c) {
    return min(a, min(b, c));
}

double g2(double a, double b) {
    return a + b - min(a,b) * 0.5;
}

double g3(double a, double b, double c) {
    return a + b + c - min3(a,b,c);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    double dp0 = 0, dp1 = INF, dp2 = INF, dp3 = INF;
    double c0 = INF, c1 = INF, c2 = INF;
    f(i,0,n){
        c2 = c1;
        c1 = c0;
        cin >> c0;
    
        dp3 = dp2;
        dp2 = dp1;
        dp1 = dp0;
        dp0 = min3(dp1 + c0, dp2 + g2(c0,c1), dp3 + g3(c0,c1,c2));
    }
    printf("%.1f", dp0);
    return 0;
}