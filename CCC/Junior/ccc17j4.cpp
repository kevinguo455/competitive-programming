// https://dmoj.ca/problem/ccc17j4
#include <iostream>

int main() {
    int n, a = 1, b = 12, c = 0, d = 0, x = 0;
    std::cin >> n;

    while (n > 1440) {
        n -= 1440;
        x += 62;
    }

    while (n >= 0) {
        if (b > 9) {
            if ((b-10) - a == c - (b-10) && d - c == c - (b-10)) {
                x++;
            }
        }
        else {
            if (d - c == c - b) {
                x++;
            }
        }

        //Increment
        d++;
        if (d > 9) {
            d = 0;
            c++;
            if (c > 5) {
                c = 0;
                b++;
                if (b > 12) {
                    b -= 12;
                }
            }
        }

        //std::cout << a << b << c << d << std::endl;

        n--;
    }

    std::cout << x;

    return 0;
}
