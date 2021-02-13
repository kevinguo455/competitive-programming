// https://dmoj.ca/problem/hkccc15s1
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7;

vector<int> v;
int binarySearch(int n) {
    int l = 0, h = v.size(), m = floor((l+h)/2);
    while (l < h) {
        if (v[m] > n) {
            h = m;
        }
        else {
            l = m+1;
        }
        m = floor((l+h)/2);
    }
    return m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, x, c = 0; cin >> n >> m;
    
    f(i,0,n){
        cin >> x;
        v.pb(x);
    }
    sort(v.begin(),v.end());

    for (int i = 0; v[i] <= m/2 && i < n; i++) {
        c += binarySearch(m-v[i]) - i - 1;
        c %= mod;
    }
    cout << c << endl;
    return 0;
}
