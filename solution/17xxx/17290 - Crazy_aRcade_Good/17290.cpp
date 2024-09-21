#include <iostream>
#include <string>
using namespace std;

int r, c, dist = 1234567890;
bool map[11][11];
string str;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    for(int i = 0; i < 10; i++) {
        cin >> str;
        for(int j = 0; j < 10; j++) {
            if(str[j] == 'o') {
                for(int k = 0; k < 10; k++) {
                    map[i][k] = true;
                    map[k][j] = true;
                }
            }
        }
    }

    r = r-1;
    c = c-1;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(map[i][j] == false) {
                dist = min(dist, abs(i-r)+abs(j-c));
            }
        }
    }

    cout << dist;

    return 0;
}