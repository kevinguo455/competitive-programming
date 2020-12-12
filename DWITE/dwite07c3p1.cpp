/*
DWITE '07 R3 #1 - Yet Another Primes Question
Key Concepts: Simple Math, Brute Force
https://dmoj.ca/problem/dwite07c3p1
Solution by Kevin Guo
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
using namespace std;

bool isPrime (int n) {
    if (n < 2) 
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    for (int test = 0; test < 5; test++) {
        int n; cin >> n; int factors = 0;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0 && isPrime(i))
               factors++;
        }
        if (factors == 3)
            cout << "valid" << endl;
        else 
            cout << "not" << endl;
    }
    return 0;
}

