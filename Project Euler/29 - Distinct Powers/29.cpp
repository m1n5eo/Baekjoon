#include <iostream>
using namespace std;

int temp[13] = {1, 4, 8, 9, 16, 25, 27, 32, 36, 49, 64, 81, 100};
bool arr[111][1111], check[111];

int main() {
    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        if(i == temp[cnt]) {
            check[i] = true;
            cnt += 1;
        }
    }

    for(int i = 2; i <= 100; i++) {
        if(check[i] == false) {
            if(i == 2) {
                for(int j = 2; j <= 100; j++) {
                    arr[i][j] = true;
                    arr[i][j*2] = true;
                    arr[i][j*3] = true;
                    arr[i][j*4] = true;
                    arr[i][j*5] = true;
                    arr[i][j*6] = true;
                }
            }
            else if(i == 3) {
                for(int j = 2; j <= 100; j++) {
                    arr[i][j] = true;
                    arr[i][j*2] = true;
                    arr[i][j*3] = true;
                    arr[i][j*4] = true;
                }
            }
            else if(4 < i && i < 11) {
                for(int j = 2; j <= 100; j++) {
                    arr[i][j] = true;
                    arr[i][j*2] = true;
                }
            }
            else {
                for(int j = 2; j <= 100; j++) {
                    arr[i][j] = true;
                }
            }
        }
    }

    cnt = 0;
    for(int i = 2; i < 111; i++) {
        for(int j = 2; j < 1111; j++) {
            if(arr[i][j] == true) {
                cnt = cnt + 1;
            }
        }
    }
    cout << cnt;
}