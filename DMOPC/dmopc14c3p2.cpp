/*
DMOPC '14 Contest 3 P2 - Not Enough Rejudging!
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc14c3p2
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
#define fi first
#define se second
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
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
    fio;

    int n; cin >> n;
    queue<string> in;
    string s;
    int wa = 0;
    f(i,0,n){
        cin >> s;
        in.push(s);
        if (s == "WA") wa++;
    }
    wa *= 3;
    wa /= 10;
    int ir = 0;
    while (!in.empty()) {
        if (in.front() == "AC") cout << "AC\n";
        else if (in.front() == "TLE") cout << "WA\n";
        else if (in.front() == "WA") {
            if (wa > 0) cout << "AC\n";
            else cout << "WA\n";
            wa--;
        }
        else if (in.front() == "IR") {
            if (ir < 10) cout << "AC\n";
            else if (ir < 20) cout << "WA\n";
            else cout << "IR\n";
            ir++;
        }
        in.pop();
    }

    return 0;
}