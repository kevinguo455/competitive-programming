// https://dmoj.ca/problem/ccc16j3
#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;

    int top = 1, j = 0;

    for (int i = 0; i < word.length(); i++) { /* 1 letter centers */
        j = 0;

        while ((i - j >= 0) && ((i + j) < word.length())) {
            if (word[i-j] != word[i+j]) {
                break;
            }
            j++;
        }

        if (j*2-1 > top) {
            top = j*2-1;
        }
    }

    for (int i = 0; i < word.length() - 1; i++) { /* 2 letter centers */
        j = 0;
        if (word[i] == word[i+1]) {
            while ((i - j >= 0) && ((i + j + 1) < word.length())) {
                if (word[i-j] != word[i+j+1]) {
                    break;
                }
                j++;
            }

            if (j*2 >= top) {
                top = j*2;
            }
        }
    }

    std::cout << top;

    return 0;
}