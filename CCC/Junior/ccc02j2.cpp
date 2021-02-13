// https://dmoj.ca/problem/ccc02j2
#include <iostream>
#include <string>

int vowel(char x) {
    if (x % 32 == 1 || x % 32 == 5 || x % 32 == 9 || x % 32 == 15 || x % 32 == 21 || x % 32 == 25) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    std::string word;
    std::cin >> word;

    while (word != "quit!") {
        if (word.length() > 4 && vowel(word[word.length() - 3]) == 0 && word[word.length() - 2] == 111 && word[word.length() - 1] == 114) {
            for (int i = 0; i < word.length() - 1; i++) {
                std::cout << word[i];
            }
            std::cout << "ur" << std::endl;
        }
        else {
            std::cout << word << std::endl;
        }

        std::cin >> word;
    }

    return 0;
}