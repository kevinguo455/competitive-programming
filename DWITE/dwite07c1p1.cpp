/*
DWITE '07 R1 #1 - Vanilla Primes
Key Concepts: Simple Math
https://dmoj.ca/problem/dwite07c1p1
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
    int n; cin >> n; 
    if (isPrime(n)) 
        cout << "prime" << endl;
    else
        cout << "not" << endl;    
    return 0;
}