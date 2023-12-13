#include <iostream>
using namespace std;

int arr[111][111];

int main() {
    int n;
    cin >> n;

    int i = 0, j = 0, sw = 0, temp = 1;
    while(true) {
        arr[i][j] = temp;
        temp += 1;

        if(temp-1 == n*n) break;

        if(sw == 0) {
            if(i == n-1 || j == 0) {
                sw = 1;
                if(i == n-1) j = j+1;
                else if(j == 0) i = i+1;
            }
            else {
                i = i+1;
                j = j-1;
            }
        }
        else if(sw == 1) {
            if(i == 0 || j == n-1) {
                sw = 0;
                if(j == n-1) i = i+1;
                else if(i == 0) j = j+1;
            }
            else {
                i = i-1;
                j = j+1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}