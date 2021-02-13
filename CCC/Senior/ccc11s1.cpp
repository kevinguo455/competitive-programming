// https://dmoj.ca/problem/ccc11s1
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 0, s = 0;
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string text;
        getline(cin, text);
        for (unsigned int j = 0; j < text.length(); j++) {
            if (text[j] == 't' || text[j] == 'T') {
                t++;
            }
            else if (text[j] == 's' || text[j] == 'S') {
                s++;
            }
        }
    }
    cout << (t > s ? "English" : "French") << endl;
    return 0;
}