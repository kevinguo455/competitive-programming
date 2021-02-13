// https://dmoj.ca/problem/ccc02s1
#include <iostream>
#include <math.h>

int main() {
    int a, b, c, d, n, x = 0, m = 2000000;
    std::cin >> a >> b >> c >> d >> n;

    for (int i = 0; i <= n/a; i++) {
        for (int j = 0; j <= n/b; j++) {
            for (int k = 0; k <= n/c; k++) {
                for (int l = 0; l <= n/d; l++) {
                    if (i*a+j*b+k*c+l*d == n) {
                        x++;
                        if (i+j+k+l<m) {
                            m = i+j+k+l;
                        }
                        std::cout << "# of PINK is " << i << " # of GREEN is " << j << " # of RED is " << k << " # of ORANGE is " << l << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "Total combinations is " << x << "." << std::endl << "Minimum number of tickets to print is " << m << ".";

    return 0;
}