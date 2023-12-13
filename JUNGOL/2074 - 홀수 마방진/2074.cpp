#include <iostream>
using namespace std;

int arr[111][111];

int main() {
    int n;
    cin >> n;

    int i = 0, j = n/2, cnt = 0;
    while(true) {
        arr[i][j] = ++cnt;

        if(cnt == n*n) break;

        if(cnt%n == 0) {
            i = i+1;
        }
        else if(i == 0) {
            i = n-1;
            j = j-1;
        }
        else if(j == 0) {
            i = i-1;
            j = n-1;
        }
        else {
            i = i-1;
            j = j-1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}