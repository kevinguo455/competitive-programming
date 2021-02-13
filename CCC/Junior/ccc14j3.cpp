// https://dmoj.ca/problem/ccc14j3
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <tuple>

using namespace std;

int main() {
    int n, n1, n2, a = 100, b = 100;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> n1 >> n2;
        if (n1 > n2) 
            b -= n1; 
        else if (n2 > n1)
            a -= n2;
    }
    cout << a << endl << b;

    return 0;
}