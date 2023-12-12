#include <iostream>
using namespace std;

int arr[33][33];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        arr[i][i] = 1;
        arr[i][0] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }

    if(m == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else if(m == 2) {
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < n-i-1; j++) cout << " ";
            for(int j = 0; j <= i; j++) cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
    else if(m == 3) {
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                cout << arr[n+j-i-1][j] << " ";
            }
            cout << "\n";
        }
    }
}