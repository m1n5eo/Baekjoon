#include <iostream>
using namespace std;

int main() {
    char arr[111][111];

    int n;
    cin >> n;

    char cnt = 'A';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = cnt;
            if(cnt == 'Z') cnt = 'A';
            else cnt += 1;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}