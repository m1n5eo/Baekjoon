#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y, max_arr = -1, arr[9][9];

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if(arr[i][j] > max_arr) {
                max_arr = arr[i][j];
                x = i+1; y = j+1;
            }
        }
    }
    cout << max_arr << "\n" << x << " " << y;
}