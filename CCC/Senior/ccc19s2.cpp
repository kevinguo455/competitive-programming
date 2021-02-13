// https://dmoj.ca/problem/ccc19s2
#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
using namespace std;

bool isPrime (int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int cases, n; cin >> cases;
    for (int test = 0; test < cases; test++) {
        cin >> n;
        int i = n, j = n;
        n *= 2;

        while (true) {
            if (i + j > n || !isPrime(i)) 
                i--;
            else if (i + j < n || !isPrime(j))
                j++;
            else
                break;
        }
        cout << i << " " << j << endl;
    }
    return 0;
}