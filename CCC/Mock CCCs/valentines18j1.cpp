/*
Valentine's Day '18 Junior P1 - The Cactus Number
Key Concepts: Implementation
https://dmoj.ca/problem/valentines18j1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 105;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n, x; cin >> n;
    bool c = 0, b = 0;
    f(i,0,n) {
        cin >> x;
        if (x > 1000) b = 1;
        if (x > 10000) c = 1;
    }
    if (c) cout << "Something is wrong with these cuteness values" << endl;
    else if (b) cout << "Cuteness by definition is similarity to Cactus" << endl;
    else cout << "Cuteness by definition is similarity to Carol" << endl;

    return 0;
}