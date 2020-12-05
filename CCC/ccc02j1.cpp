// https://dmoj.ca/problem/ccc02j1
#include <iostream>

char l = 108, r = 114, b = 98;

void h() {
    std::cout << " * * *" << std::endl;
}

void v(char s) {
    if (s == l) {
        for (int i = 0; i < 3; i++) {
            std::cout << "*" << std::endl;
        }
    }
    else if (s == r) {
        for (int i = 0; i < 3; i++) {
            std::cout << "      *" << std::endl;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            std::cout << "*     *" << std::endl;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    switch (n) {
        case 0:
            h();
            v(b);
            std::cout << std::endl;
            v(b);
            h();
            break;
        case 1:
            std::cout << std::endl;
            v(r);
            std::cout << std::endl;
            v(r);
            std::cout << std::endl;
            break;
        case 2:
            h();
            v(r);
            h();
            v(l);
            h();
            break;
        case 3:
            h();
            v(r);
            h();
            v(r);
            h();
            break;
        case 4:
            std::cout << std::endl;
            v(b);
            h();
            v(r);
            std::cout << std::endl;
            break;
        case 5:
            h();
            v(l);
            h();
            v(r);
            h();
            break;
        case 6:
            h();
            v(l);
            h();
            v(b);
            h();
            break;
        case 7:
            h();
            v(r);
            std::cout << std::endl;
            v(r);
            std::cout << std::endl;
            break;
        case 8:
            h();
            v(b);
            h();
            v(b);
            h();
            break;
        case 9:
            h();
            v(b);
            h();
            v(r);
            h();
            break;
    }
    //std::cout << std::endl;
    return 0;
}