// https://dmoj.ca/problem/ccc06s1
#include <iostream>
#include <string>

int main() {
    std::string mom, dad, kid = "";
    int n = 0;
    std::cin >> mom >> dad >> n;

    for (int i = 0; i < n; i++) {
        kid = "";
        std::cin >> kid;
        for (int j = 0; j < 5; j++) {
            if (kid[j] < 91) {
                if ((mom[j*2] < 91 || mom[j*2+1] < 91) || (dad[j*2] < 91 || dad[j*2+1] < 91)) {
                    /* Possible */
                }
                else {
                    std::cout << "Not their baby!";
                    break;
                }
            }
            else {
                if ((mom[j*2] > 91 || mom[j*2+1] > 91) && (dad[j*2] > 91 || dad[j*2+1] > 91 )) {
                    /* Possible */
                }
                else {
                    std::cout << "Not their baby!";
                    break;
                }
            }
            if (j == 4) {
                std::cout << "Possible baby.";
            }
        }
        if (i != n-1) {
            std::cout << std::endl;
        }
    }

    return 0;
}