#include <iostream>
using namespace std;

int main() {
    int first[3], second[3];
    for(int i = 0; i < 3; i++) cin >> first[i];
    for(int i = 0; i < 3; i++) cin >> second[i];

    for(int x = -999; x <= 999; x++) {
        for(int y = -999; y <= 999; y++) {
            if(first[0]*x + first[1]*y == first[2] && second[0]*x + second[1]*y == second[2]) {
                cout << x << " " << y;
                return 0;
            }
        }
    }
}