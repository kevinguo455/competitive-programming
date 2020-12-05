// https://dmoj.ca/problem/ccc15s3
#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, p, score = 0;
    scanf("%d%d", &g, &p);
    set<int> gates;
    for (int i = 0; i < g; i++) 
        gates.insert(i);

    for (int i = 0; i < p; i++) {
        int n; scanf("%d", &n);
        n = g - n;
        set<int>::iterator it = gates.lower_bound(n);
        if (it == gates.end())
            break;
        gates.erase(*it);
        score++;
    }
    printf("%d", score);
    return 0;
}
