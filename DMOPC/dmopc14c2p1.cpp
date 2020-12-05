// https://dmoj.ca/problem/dmopc14c2p1
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n+1; i++) {
        int d;
        scanf("%d", &d);
        int sum = 0;
        for (int j = 0; j < d; j++) {
            int t;
            scanf("%d", &t);
            sum += t;
        }
        if (sum == 0) {
            printf("Weekend\n");
        }
        else {
            printf("Day %d: %d\n", i, sum);
        }
    }

    return 0;
}