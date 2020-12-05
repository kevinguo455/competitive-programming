// https://dmoj.ca/problem/ccc12j2
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a < b && b < c && c < d) 
        cout << "Fish Rising" << endl;
    else if (a > b && b > c && c > d) 
        cout << "Fish Diving" << endl;
    else if (a == b && b == c && c == d)
        cout << "Fish At Constant Depth" << endl;
    else 
        cout << "No Fish" << endl;

    return 0;
}
