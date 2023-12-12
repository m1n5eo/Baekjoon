#include <iostream>
using namespace std;

int arr[111][111];

int main() {
    int n;
    cin >> n;

    int i = 0, j = 0, sw = 0, cnt = 1;
    while(true) {
        arr[i][j] = cnt;
        cnt += 1;

        if(cnt-1 == n*n) break;

        if(sw == 0) {
            if(j+1 == n || arr[i][j+1] != 0) {
                i = i+1;
                sw = 1;
            }
            else j = j+1;
        }
        else if(sw == 1) {
            if(i+1 == n || arr[i+1][j] != 0) {
                j = j-1;
                sw = 2;
            }
            else i = i+1;
        }
        else if(sw == 2) {
            if(j == 0 || arr[i][j-1] != 0) {
                i = i-1;
                sw = 3;
            }
            else j = j-1;
        }
        else if(sw == 3) {
            if(i == 0 || arr[i-1][j] != 0) {
                j = j+1;
                sw = 0;
            }
            else i = i-1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= 0; j--) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}