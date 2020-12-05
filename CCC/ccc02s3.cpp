// https://dmoj.ca/problem/ccc02s3
#include <iostream>
#include <string>
#include <vector>

int main() {
    //Initializing data
    std::vector<std::string> backyard;
    int w, l;
    std::cin >> w >> l;
    std::string buffer;
    for (int i = 0; i < w; i++) {
        std::cin >> buffer;
        backyard.push_back(buffer);
    }
    int moves;
    std::cin >> moves;
    char buffer2;
    std::vector<char> path;
    for (int i = 0; i < moves; i++) {
        std::cin >> buffer2;
        path.push_back(buffer2);
    }
    //Logic
    int x, y, f;
    bool pass;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < l; j++) {
            //Start at backyard[i][j]
            for (int k = 0; k < 4; k++) {
                x = j;
                y = i;
                f = k;
                pass = true;
                for (int pos = 0; pos < moves; pos++) {
                    if (path[pos] == 'F') {
                        if (backyard[y][x] == 'X') {
                            pass = false;
                            break;
                        }
                        if (f == 0) {
                            x++;
                        }
                        else if (f == 1) {
                            y--;
                        }
                        else if (f == 2) {
                            x--;
                        }
                        else if (f == 3) {
                            y++;
                        }
                        //check collision
                        if (x >= l || x < 0 || y >= w || y < 0) {
                            pass = false;
                            break;
                        }
                        else if (backyard[y][x] == 'X') {
                            pass = false;
                            break;
                        }
                    }
                    else if (path[pos] == 'L') {
                        f++;
                        if (f == 4) {
                            f = 0;
                        }
                    }
                    else if (path[pos] == 'R') {
                        f--;
                        if (f == -1) {
                            f = 3;
                        }
                    }
                }
                if (pass == true) {
                    backyard[y][x] = '*';
                    //std::cout << i << " " << j << " " << k << std::endl;
                }
            }
        }
    }
    //Output
    for (int i = 0; i < w; i++) {
        std::cout << backyard[i] << std::endl;
    }
    return 0;
}