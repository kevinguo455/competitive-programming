// https://dmoj.ca/problem/ccc04j4
#include <iostream>
#include <string>

std::string plain(std::string text) {  /* Removes all non-text characters from string */
    std::string out = "";
    for (int i = 0; i < text.length(); i++) {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123)) {
            out += text[i];
        }
    }
    return out;
}

int main() {
    std::string key, phrase;
    std::cin >> key;
    std::cin.ignore();
    getline(std::cin, phrase);
    phrase = plain(phrase);

    for (int i = 0; i < key.length(); i++) {
        for (int j = i; j < phrase.length(); j += key.length()) {
            phrase[j] = ((phrase[j] - 64) + (key[i] - 65)) % 26 + 64;
            if (phrase[j] == 64) {
                phrase[j] += 26;
            }
        }
    }

    std::cout << phrase;

    return 0;
}