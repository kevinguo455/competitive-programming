// https://dmoj.ca/problem/ccc14s3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t, n, x; cin >> t;
    f(i,0,t){
        stack<int> top;
        stack<int> branch;
        top.push(0);
        branch.push(0);
        cin >> n;
        f(j,0,n){
            cin >> x;
            top.push(x);
        }

        int next = 1;
        while (true){
            if (next > n) {
                cout << "Y" << endl;
                break;
            }
            if (top.top() == next) {
                top.pop();
                next++;
            }
            else if (branch.top() == next) {
                branch.pop();
                next++;
            }
            else if (top.top() == 0) {
                cout << "N" << endl;
                break;
            }
            else {
                branch.push(top.top());
                top.pop();
            }
        }
    }
    return 0;
}