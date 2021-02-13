// https://dmoj.ca/problem/ccc11s2
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    char c;
    queue<char> q;
    int n, x = 0; cin >> n;
    f(i,0,n){
        cin >> c;
        q.push(c);
    }
    f(i,0,n){
        cin >> c;
        if (c == q.front()) 
            x++;
        q.pop();
    }
    cout << x << endl;

    return 0;
}