// https://dmoj.ca/problem/ccc15j3
#include <iostream>
#include <string>

int vowel(char x) {
    if (x % 32 == 1 || x % 32 == 5 || x % 32 == 9 || x % 32 == 15 || x % 32 == 21) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    std::string word;
    std::cin >> word;
    char output;

    for (int i = 0; i < word.length(); i++) {
        std::cout << word[i];
        if (vowel(word[i]) == 0) {
            for (int j = 1; j < 10; j++) {
                if (vowel(word[i]-j) == 1) {
                    output = word[i]-j;
                    std::cout << output;
                    break;
                }
                else if (vowel(word[i]+j) == 1) {
                    output = word[i]+j;
                    std::cout << output;
                    break;
                }
            }

            if (word[i] == 122) {
                std::cout << word[i];
            }
            else if (vowel(word[i]+1) == 1) {
                output = word[i]+2;
                std::cout << output;
            }
            else {
                output = word[i]+1;
                std::cout << output;
            }
        }
    }

    return 0;
}