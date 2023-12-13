#include <iostream>
using namespace std;

char arr[222][222];

int main() {
    int stop[111] = {0, 1, };
    for(int i = 2; i <= 100; i++) {
        stop[i] = stop[i-1]+(i-1)*4;
    }

    int n;
    cin >> n;

    int num = n*2-1, i = 0, j = n-1, sw = 0, cnt = 0;
    char temp = 'A';
    while(true) {
        arr[i][j] = temp;
        if(temp == 'Z') temp = 'A';
        else temp += 1;

        cnt += 1;
        if(cnt == stop[n]) break;
        // if(i < 0 || i >= num || j < 0 || j >= num) break;

        if(sw == 0) {
            if(j == 0 || arr[i+1][j] != 0) {
                sw = 1;
                i = i+1;
                j = j+1;
            }
            else {
                i = i+1;
                j = j-1;
            }
        }
        else if(sw == 1) {
            if(i == num-1 || arr[i][j+1] != 0) {
                sw = 2;
                i = i-1;
                j = j+1;
            }
            else {
                i = i+1;
                j = j+1;
            }
        }
        else if(sw == 2) {
            if(j == num-1 || arr[i-1][j] != 0) {
                sw = 3;
                if(arr[i-1][j-1] != 0) {
                    j = j-1;
                }
                else {
                    i = i-1;
                    j = j-1;
                }
            }
            else {
                i = i-1;
                j = j+1;
            }
        }
        else if(sw == 3) {
            if(i == 0 || arr[i][j-1] != 0 || arr[i-1][j-1] != 0) {
                sw = 0;
                j = j-1;
            }
            else {
                i = i-1;
                j = j-1;
            }
        }
    }

    for(int i = 0; i < n*2; i++) {
        for(int j = 0; j < n*2; j++) {
            if(arr[i][j] == 0) cout << "  ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}