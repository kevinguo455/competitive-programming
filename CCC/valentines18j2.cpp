/*
Valentine's Day '18 Junior P2 - Stop the Scammer
Key Concepts: Simulation
https://dmoj.ca/problem/valentines18j2
Solution by Kevin Guo
*/
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
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e4+5;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n, x, y; cin >> n >> x >> y;
    int a = x, c = 1;
    while (a * 2 < n) {
        x -= y;
        c++;
        a += x;
        if (x < 0) {
            cout << "RIP" << endl;
            return 0;
        }
    }
    cout << c << endl;
    return 0;
}