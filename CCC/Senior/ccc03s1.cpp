// https://dmoj.ca/problem/ccc03s1
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

    int n = 1, x; cin >> x;
    while (x != 0) {
        if (n + x <= 100) n += x;
        // ladders
        if (n == 9) n = 34;
        else if (n == 40) n = 64;
        else if (n == 67) n = 86;
        // snakes
        else if (n == 54) n = 19;
        else if (n == 90) n = 48;
        else if (n == 99) n = 77;

        cout << "You are now on square " << n << endl;
        // win
        if (n == 100) {
            cout << "You Win!" << endl;
            return 0;
        }
        cin >> x;
    }
    cout << "You Quit!" << endl;
    return 0;
}