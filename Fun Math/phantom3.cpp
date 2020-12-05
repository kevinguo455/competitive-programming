// https://dmoj.ca/problem/phantom3
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void baseSieve(int n, vector<int>& primes) {
    vector<bool> isPrime(n, true);   
    for (int i = 2; i < n; i++) {
        if (isPrime[i] == true) {
            primes.push_back(i);
            for (int j = i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    long long int lower, upper;
    cin >> lower >> upper;

    vector<int> factorPrimes;
    int limit = floor(sqrt(upper));
    baseSieve(limit, factorPrimes);

    int range = upper - lower;
    vector<bool> isPrime(range, true);
    for (unsigned int i = 0; i < factorPrimes.size(); i++) {
        long long int a = ceil(static_cast<double>(lower) / factorPrimes[i]) * factorPrimes[i];
        for (long long int j = a; j < upper; j += factorPrimes[i]) {
            isPrime[j - lower] = false; 
        }
    }
    
    int count = 0;
    for (unsigned int i = 0; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    cout << count;

    return 0;
}