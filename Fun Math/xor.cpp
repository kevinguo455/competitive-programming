// https://dmoj.ca/problem/xor
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int sum = 0;
        int x = a % 4;
        int y = b % 4;

        for (int j = a; j < a + 4 - x; j++) 
            sum = sum ^ j;
        for (int j = b; j >= b - y; j--) 
            sum = sum ^ j;

        cout << sum << endl;
    }
    
    return 0;
}
