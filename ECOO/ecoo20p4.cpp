/*
ECOO '20 P4 - Ring
Key Concepts: Implementation, Dynamic Programming
https://dmoj.ca/problem/ecoo20p4
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

    int cases; cin >> cases;
    f(casen,0,cases){
        int lines; cin >> lines;
        
        map<string, pll> functions;         // all functions that have been defined
        stack<pair<string, pll>> defining;  // all functions currently being defined (nested definitions)
        ll a = 1, b = 0;                    // all functions can be expressed as (ax + b)

        f(line,0,lines){
            string s, t; cin >> s;
            ll n = 0;
            if (s == "ADD") {
                cin >> n;
                b += n;                     // (ax+b) + n
            }
            else if (s == "SUB") {
                cin >> n;
                b -= n;                     // (ax+b) - n
            }
            else if (s == "MULT") {
                cin >> n;
                a = (a * n) % MOD;          // (ax+b) * n
                b = (b * n) % MOD;
            }
            else if (s == "FUN") {
                cin >> t;
                defining.push({t, {a,b}});  // push the function name being defined
                a = 1;                      // and current a and b vals
                b = 0;
            }
            else if (s == "END") {
                functions.insert({defining.top().fi, {a,b}});

                /* If nested function definitions apply to the outer function

                defining.top().se.fi = mod(defining.top().se.fi * a);   // update current ax+b with function
                defining.top().se.se = mod(defining.top().se.se * a);
                b = mod(b + mod(a * defining.top().se.se));
                a = mod(a * defining.top().se.fi);

                */
                a = defining.top().se.fi;   // restore current ax+b to before function declaration
                b = defining.top().se.se;

                defining.pop();         
            }
            else if (s == "CALL") {
                cin >> t;
                a = (a * functions.at(t).fi) % MOD;
                b = (b * functions.at(t).fi) % MOD;     // a(ax+b) + b
                b = (b + functions.at(t).se) % MOD;
            }
        }
        while (b < 0) b += MOD;     // positive mod
        cout << b % MOD << endl;
    }

    return 0;
}