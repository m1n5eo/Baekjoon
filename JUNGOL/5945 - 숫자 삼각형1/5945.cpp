#include <iostream>
using namespace std;

int arr[55][55];

int main() {
    int n;
    cin >> n;

    if(n%2 == 0 || !(1 <= n && n <= 50)) {
        cout << "INPUT ERROR!";
        return 0;
    }

    int i = 0, j = 0, sw = 0, cnt = 1;
    while(true) {
        arr[i][j] = cnt++;

        if(n%2 == 1 && i == n-1 && j == n-1) break;

        if(sw == 0) {
            if(j == i) {
                i = i+1;
                j = j+1;
                sw = 1;
            }
            else j = j+1;
        }
        else if(sw == 1) {
            if(j == 0) {
                i = i+1;
                sw = 0;
            }
            else j = j-1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}