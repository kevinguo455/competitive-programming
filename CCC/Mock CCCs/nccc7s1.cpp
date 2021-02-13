#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    cout << a * b / 2 << (a * b % 2 == 1 ? ".5\n" : ".0\n");
    return 0;
}